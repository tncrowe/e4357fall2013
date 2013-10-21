/* 
 * File: hw1_lib.c
 * gcc -c hw1_lib.c -o hw1_lib.o
 * gcc -S hw1_lib.c -o hw1_lib.s
 * objdump -D hw1_lib.o
 */
#include "hw1_lib.h"

uint16_t binary_to_gray(uint16_t gray)
{
   uint16_t shift_by_one = gray >> 1;

   gray = shift_by_one ^ gray;
   
   return gray;
}

uint16_t gray_to_binary(uint16_t gray)
{
	uint16_t result = gray & (1 << 15); 
	
	result |= (gray ^ (result >> 1)) & (1 << 14);
	result |= (gray ^ (result >> 1)) & (1 << 13);
	result |= (gray ^ (result >> 1)) & (1 << 12);
	result |= (gray ^ (result >> 1)) & (1 << 11);
	result |= (gray ^ (result >> 1)) & (1 << 10);
	result |= (gray ^ (result >> 1)) & (1 << 9);
	result |= (gray ^ (result >> 1)) & (1 << 8);
	result |= (gray ^ (result >> 1)) & (1 << 7);
	result |= (gray ^ (result >> 1)) & (1 << 6);
	result |= (gray ^ (result >> 1)) & (1 << 5);
	result |= (gray ^ (result >> 1)) & (1 << 4);
	result |= (gray ^ (result >> 1)) & (1 << 3);
	result |= (gray ^ (result >> 1)) & (1 << 2);
	result |= (gray ^ (result >> 1)) & (1 << 1);
	result |= (gray ^ (result >> 1)) & (1 );

	return result;

}



