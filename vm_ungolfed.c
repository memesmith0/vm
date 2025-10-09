// VM Core - Refactored for Readability
// Author: John Morris Beck
// License: GPLv2 (found at gnu.org)
// Compile with: gcc -std=c99 -O3 -march=native -flto vm_readable_refactored.c -o vm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- MACROS FOR READABILITY AND COMPACTNESS ---

// Define the handler block structure: case X: Y; break;
#define OP_HANDLER(op_code, operation) case op_code: { operation; } break;

// Macros to simplify access to register values based on the currently loaded indices (a and b)
// Note: These macros use 'a' and 'b' (now reg_a_idx and reg_b_idx) which are loaded once per loop.
#define PTR_REG_A_VAL       ptr_registers[reg_a_idx]    // Pointer Register A (for memory operations)
#define INT_REG_A_VAL       int_registers[reg_a_idx]    // Integer Register A (destination/source)
#define INT_REG_B_VAL       int_registers[reg_b_idx]    // Integer Register B (source/size)

// --- GLOBAL STATE ---

// 'counter': Used for initialization loop and temporarily for input size.
int counter = 256;

// General Purpose Registers (GPRs):
// 'int_registers': 256 integer registers (4-byte data).
// 'ptr_registers': 256 pointer registers (memory addresses).
int int_registers[256];
void* ptr_registers[256];

// Program Memory: Stores the compiled instructions (8KB of space for opcodes/operands).
// Note: In the golfed version, this was defined as int z[8192].
int program_memory[8192];

// Instruction Operand Registers (used locally within the loop for speed):
// 'reg_a_idx': Index for the destination/source A register (R1).
// 'reg_b_idx': Index for the source B register (R2) or byte count/size.
int reg_a_idx, reg_b_idx;

// Instruction Pointer (IP) / Execution Flag
// 'ip': Program counter, points to the current opcode in program_memory.
// 'is_running': Flag to control the main execution loop (1 = running, 0 = halt).
int *ip = program_memory;
int is_running = 1;

// --- MAIN VM EXECUTION ---
int main() {
    // Note: The variable names below match the original single-character names
    //       to show the direct correspondence, but are used in a much clearer way.
    
    // --- 1. INITIALIZE REGISTERS (256 iterations) ---
    // Initialize all 256 int_registers to 1.
    // Initialize all 256 ptr_registers to point to register 1's address (a safe default).
    while (counter--) {
        int_registers[counter] = 1;
        ptr_registers[counter] = &ptr_registers[1];
    }
    
    // --- 2. LOAD PROGRAM FROM STDIN ---
    // Read the first character (ignored in this setup)
    counter = getc(stdin);

    // Load instructions from stdin until a newline is found (program ends on first newline)
    // The instruction set is loaded directly into the program_memory array (z).
    // The 'counter' variable is repurposed here to track the instruction count (i++).
    while ('\n' - (program_memory[counter++] = getc(stdin)));

    // Reset instruction pointer to the beginning of the loaded program.
    ip = program_memory;

    // --- 3. MAIN EXECUTION LOOP (DISPATCH) ---
    while (is_running) {
        
        // --- FETCH CYCLE ---
        // 1. Load operands into local variables (CPU registers) for speed.
        reg_a_idx = *(ip + 1); // Destination/Source Register Index
        reg_b_idx = *(ip + 2); // Source/Size Register Index
        
        // 2. Load the Opcode.
        int opcode = *ip;

        // --- DECODE & EXECUTE CYCLE (Jump Table Optimization) ---
        // Opcode 0: Subtract, Opcode 1: Compare, Opcode 2: Jump/Call...
        switch (opcode) {
            
            // 0: SUB - INT_REG_A_VAL = INT_REG_A_VAL - INT_REG_B_VAL
            OP_HANDLER(0, INT_REG_A_VAL = INT_REG_A_VAL - INT_REG_B_VAL)

            // 1: CMP/SET - INT_REG_A_VAL = (INT_REG_A_VAL < INT_REG_B_VAL)
            OP_HANDLER(1, INT_REG_A_VAL = INT_REG_A_VAL < INT_REG_B_VAL)
            
            // 2: JMP - Set IP to the address stored in PTR_REG_A_VAL.
            // Note: Compiler must pre-wind jump targets by 3 due to the h+=3 advance below.
            OP_HANDLER(2, ip = (int*)PTR_REG_A_VAL)
            
            // 3: PTR_ADD - PTR_REG_A_VAL = PTR_REG_A_VAL + INT_REG_A_VAL (Byte Address Offset)
            OP_HANDLER(3, PTR_REG_A_VAL = (void*)((char*)PTR_REG_A_VAL + INT_REG_A_VAL))

            // 4: MEM_COPY - Copy value from PTR_REG_A_VAL to R[reg_b_idx].
            // Note: The integer value (INT_REG_A_VAL) is used as the size (f=e).
            OP_HANDLER(4, { INT_REG_B_VAL = INT_REG_A_VAL; ptr_registers[reg_b_idx] = PTR_REG_A_VAL; })

            // 5: MALLOC - Allocate INT_REG_A_VAL bytes and store pointer in R[reg_b_idx].
            // If allocation fails, set INT_REG_A_VAL (e) to 1.
            OP_HANDLER(5, {
                ptr_registers[reg_b_idx] = malloc(INT_REG_A_VAL);
                INT_REG_A_VAL = (ptr_registers[reg_b_idx] == NULL);
            })

            // 6: FREE - Free the memory pointed to by PTR_REG_A_VAL.
            OP_HANDLER(6, free(PTR_REG_A_VAL))

            // 7: READ - Read INT_REG_B_VAL bytes into memory starting at PTR_REG_A_VAL from stdin.
            OP_HANDLER(7, fread(PTR_REG_A_VAL, 1, INT_REG_B_VAL, stdin))
            
            // 8: WRITE - Write INT_REG_B_VAL bytes from PTR_REG_A_VAL to stdout.
            OP_HANDLER(8, fwrite(PTR_REG_A_VAL, 1, INT_REG_B_VAL, stdout))

            // 9: FLUSH - Flush the stdout buffer.
            OP_HANDLER(9, fflush(stdout))

            // 10: HALT - Stop execution.
            OP_HANDLER(10, is_running = 0)
        }
        
        // Advance Instruction Pointer: Fixed advance by 3 to the next instruction.
        // This relies on jump targets being pre-wound by 3 by the compiler.
        ip += 3;
    }

    // Explicit return 0 for C standard compliance (though optional in C99 main).
    return 0;
}
