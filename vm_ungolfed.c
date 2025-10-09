//vm.c john morris beck - Refactored for Readability
// The license to use this code is gpl2, found at gnu.org
// compile: with gcc -std=c99 -O3 -march=native -flto vm_readable.c -o vm
//
// This is a minimal, single-file, register-based Virtual Machine designed for speed
// and compactness. It uses 3-slot instructions: [Opcode, Register A, Register B].

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// --- Core VM Abstraction Macros ---

// INSTRUCTION: Defines a case handler for an opcode in the dispatch switch.
// x = opcode symbol/value, y = C code body. This replaces the golfed 'k' macro.
#define INSTRUCTION(opcode, body) case opcode: body; break;

// Register/Operand Abstraction: Maps register indices (reg_a, reg_b) to the actual storage arrays.
// This abstract layer makes the instruction implementation cleaner.
#define OP_REG_A      GPR_INT_REGISTERS[reg_a]  // Value in General Purpose Register A (Read/Write)
#define OP_REG_B      GPR_INT_REGISTERS[reg_b]  // Value in General Purpose Register B (Read Only for most ops)
#define PTR_REG_A     RES_PTR_REGISTERS[reg_a]  // Pointer/Resource in Register A (Used for memory/I/O)

// DISPATCH_LOOP: Contains the entire fetch-decode-execute cycle and the full instruction set.
// The arguments (OP_SUB, OP_LT, etc.) are the opcode values used in the bytecode.
#define DISPATCH_LOOP(OP_SUB, OP_LT, OP_JUMP, OP_PTR_ADD, OP_MEM_CPY, OP_MOVE, \
                      OP_MALLOC, OP_FREE, OP_FREAD, OP_FWRITE, OP_FLUSH, OP_HALT) \
while(is_running) { \
    /* --- DECODE PHASE (3-slot instruction format) --- */ \
    /* IP points to the Opcode. */ \
    opcode = *IP; \
    /* The next two slots are register indices (Operands A and B). */ \
    reg_a = *(IP + 1); \
    reg_b = *(IP + 2); \
    /* Assume a standard instruction length of 3 slots. */ \
    IP_INCREMENT = 3; \
    \
    /* --- EXECUTE PHASE (Instruction Dispatch) --- */ \
    switch(opcode) { \
        /* --- ARITHMETIC / LOGIC --- */ \
        INSTRUCTION(OP_SUB, OP_REG_A = OP_REG_A - OP_REG_B) \
        INSTRUCTION(OP_LT, OP_REG_A = (OP_REG_A < OP_REG_B)) /* Stores 0 or 1 in Reg A */ \
        \
        /* --- CONTROL FLOW --- */ \
        INSTRUCTION(OP_JUMP, { \
            /* Jumps to the address stored in the Resource Register A (Pointer Register) */ \
            IP = (int*)PTR_REG_A; \
            /* Since the new IP is explicitly set, do not increment it after the switch. */ \
            IP_INCREMENT = 0; \
        }) \
        INSTRUCTION(OP_HALT, is_running = 0) \
        \
        /* --- POINTER/MEMORY MANIPULATION --- */ \
        INSTRUCTION(OP_PTR_ADD, PTR_REG_A = (void*)((char*)PTR_REG_A + (int)OP_REG_A)) \
        INSTRUCTION(OP_MEM_CPY, memcpy(RES_PTR_REGISTERS[reg_b], PTR_REG_A, OP_REG_B)) \
        INSTRUCTION(OP_MOVE, OP_REG_A = OP_REG_B) /* Move integer value from Reg B to Reg A */ \
        \
        /* --- HEAP MANAGEMENT --- */ \
        INSTRUCTION(OP_MALLOC, { \
            PTR_REG_A = malloc(OP_REG_B); /* Malloc size stored in integer Reg B */ \
            /* Set Integer Reg B to the result of the allocation (0 or 1 for success/fail). */ \
            OP_REG_B = (PTR_REG_A == NULL); \
        }) \
        INSTRUCTION(OP_FREE, free(RES_PTR_REGISTERS[reg_b])) /* Free memory pointed to by Resource Reg B */ \
        \
        /* --- I/O OPERATIONS (Stream access) --- */ \
        INSTRUCTION(OP_FREAD, fread(PTR_REG_A, 1, OP_REG_B, stdin)) /* Read 'Reg B' bytes into buffer at 'Ptr Reg A' */ \
        INSTRUCTION(OP_FWRITE, fwrite(PTR_REG_A, 1, OP_REG_B, stdout)) /* Write 'Reg B' bytes from buffer at 'Ptr Reg A' */ \
        INSTRUCTION(OP_FLUSH, fflush(stdout)) /* Flush stdout buffer */ \
    } \
    /* --- FETCH PHASE (Advance Instruction Pointer) --- */ \
    IP += IP_INCREMENT; \
}

// --- VM STATE GLOBAL ARRAYS (256 slots is the VM's limited address space) ---

// GPR_INT_REGISTERS: General Purpose Registers (Integer storage, size 256).
int GPR_INT_REGISTERS[256];

// CODE_MEMORY: The storage for the VM's bytecode instructions (size 256).
// Instructions are loaded into this array from standard input.
int CODE_MEMORY[256];

// RES_PTR_REGISTERS: Resource Registers (Void pointer storage, size 256).
// Used to store pointers to allocated memory, file handles, or instruction addresses (for JUMP).
void* RES_PTR_REGISTERS[256];

// --- Main Execution Function ---

int main() {
    // Execution state variables
    int reg_a;          // Register A index (Operand 1: destination/source)
    int reg_b;          // Register B index (Operand 2: source)
    int opcode;         // The current instruction being executed
    int IP_INCREMENT;   // How many slots to advance the Instruction Pointer after execution
    int counter = 256;  // Loop counter used for initialization and input loading

    // Pointers
    int *IP = CODE_MEMORY;       // Instruction Pointer: points to the current instruction in CODE_MEMORY
    int *input_ptr = IP;         // Pointer used temporarily to load the bytecode from stdin

    int is_running = 1; // Execution flag (1 = running, 0 = halt)

    // 1. VM State Initialization (Set all 256 registers to a default state)
    while(--counter >= 0) {
        // Default integer register value is 1 (prevents division by zero or other unexpected issues).
        GPR_INT_REGISTERS[counter] = 1;
        // All resource pointers point to a known, safe location (RES_PTR_REGISTERS[1]).
        RES_PTR_REGISTERS[counter] = &RES_PTR_REGISTERS[1];
    }

    // 2. Load Bytecode from Stdin
    // Read the very first character from stdin to determine the dispatch mode.
    counter = getc(stdin);

    // Read the remaining input (the actual bytecode) until a newline ('\n') is found.
    // The input is read directly into the CODE_MEMORY array (via input_ptr).
    while ('\n' != (*input_ptr++ = getc(stdin)));

    // Reset instruction pointer to the beginning of the loaded code
    IP = CODE_MEMORY;

    // 3. Select Instruction Set (Dispatch Mode) and Execute
    // The first character (stored in counter) selects between the two instruction sets.
    switch(counter++) {
        // 'r' mode: Uses symbolic/ASCII characters for opcodes (e.g., '-' for SUB, 'x' for JUMP).
        // This is highly compact for human-written bytecode.
        INSTRUCTION('r', DISPATCH_LOOP('-', '<', 'x', 'j', 'b', '?', 'm', 'f', 'i', 'o', '.', 'k'))
        
        // Default mode: Uses numeric opcodes 0 through 11.
        default: DISPATCH_LOOP(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11)
    }

    return 0;
}
