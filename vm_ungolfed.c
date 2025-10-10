//vm.c john morris beck the license to use this code is gpl2 found at gnu.org
//compile with:gcc -std=c99 -O3 -march=native -flto vm.c -o vm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define declare_type(a,b) (a b)
//#define define(a,b,c,d) declare_type(a,b c {d})
#define assign(a,b) ((a)=(b))
//#define declare(a,b) declare_type(a,assign(b,0))
#define access(a,b) (a[b])
#define typecast(a,b) ((a)b)
#define reference(a) (&(a))
#define loop(a,b) while(a){b}
#define binary_operation(a,b,c) ((b)a(c))
#define not(a) (!(a))
#define add(a,b) binary_operation(+,a,b)
#define subtract(a,b) binary_operation(-,a,b)
#define less_than(a,b) binary_operation(<,a,b)
#define is_equal(a,b) binary_operation(==,a,b)
#define post_increment(a) ((a)++)
#define jump_to_this_value(a,b) switch(a){b}
#define if_value_equals(a,b) case a:b;break;

#define literal_newline_character '\n'

#define false 0
#define true not(false)

#define max_char_size 256

#define starter_integer_for_user 1
#define reference_to_pointer_registers typecast(void*,pointer_registers)
#define reference_to_integer_registers typecast(void*,integer_registers)
#define reference_to_thread_of_execution reference(thread_of_execution)


#define left_pointer_operand access(pointer_registers,left_operand)
#define right_pointer_operand access(pointer_registers,right_operand)
#define left_integer_operand access(integer_registers,left_operand)
#define right_integer_operand access(integer_registers,right_operand)

#define halt return 0
#define instruction_width 3


#define subtract_operation 0
#define less_than_operation 1
#define add_to_pointer_operation 2
#define deeply_copy_pointer_operation 3
#define deeply_copy_integer_operation 4
#define allocate_memory_operation 5
#define free_memory_operation 6
#define read_operation 7
#define write_operation 8
#define halt_virtual_machine 9

int main(){
  int fetch_instruction_counter=0;
  int left_operand;
  int right_operand;
  int operator;

       
  int* integer_registers=max_char_size;
  int* initial_instruction_buffer=max_char_size;
  int* thread_of_exeuction=1;

  assign(access(thread_of_operation,0),initial_instruction_buffer);
  assign(access(integer_registers,0),starter_integer_for_user);
       
  void* pointer_registers=max_char_size;
       
  assign(access(pointer_registers,0),reference_to_pointer_registers);
  assign(access(pointer_registers,1),reference_to_integer_registers);
  assign(access(pointer_registers,2),reference_to_thread_of_execution);

  loop( not(is_equal(

		     literal_newline_character,
			  
		     assign(access(thread_of_execution,post_increment(fetch_instruction_counter)),getchar())


		     )

	    ),

	void;

	)

    loop(true,


	 assign(left_operand,access(thread_of_execution,0));
	 assign(right_operand,(access(thread_of_execution,1)));
	 assign(operator,access(thread_of_execution,2));

	 jump_to_this_value(operator,

			    if_value_equals(subtract_operation,

					    assign(left_integer_operand,(subtract(left_integer_operand,right_integer_operand)));

					    );

			    if_value_equals(less_than_operation,

					    assign(left_integer_operand,less_than(left_integer,right_integer_operand));

					    );

			    if_value_equals(add_to_pointer_operation,

					    assign(left_pointer_operand, typecast(void*,typecast(char*,add(left_pointer_operand,typecast(int,left_integer_operand)))));
			       
					    );



			    if_value_equals(deeply_copy_pointer_operation,

					    assign(access(0,typecast(int*,right_pointer_operand)),typecast(int,assign(access(0,typecast(int*,right_pointer_operand)))))
					       
					    );

			    if_value_equals(deeply_copy_integer_operation,
					       
					    assign(access(0,typecast(void*,right_pointer_operand)),access(0,typecast(void*,right_integer_operand)));
					       
					    );

			    if_value_equals(allocate_memory_operation,
					       

					    assign(right_pointer_operand, malloc(left_integer_operand));
					    assign(left_integer_operand, is_equal(right_pointer_operand,NULL));
	    
	    
					    );

			    if_value_equals(free_memory_operation,
					       
					    free(left_pointer_operand);
					       
					    );

			    if_value_equals(read_operation,

					    fread(right_pointer_operand,1,left_integer_operand,stdin);
       
					    );

			    if_value_equals(write_operation,

					    fwrite(right_pointer_operand,1,left_integer_operand,stdout);
		       
					    fflush(stdout);

					    );

			    if_value_equals(halt_virtual_machine,
					       
					    halt;
					       
					    );

			    );
	    
	 assign(thread_of_execution,add(thread_of_execution,instruction_width));

	 )
    }
       
       
       
       
