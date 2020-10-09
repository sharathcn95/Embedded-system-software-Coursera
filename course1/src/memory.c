/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading,
 * writing to memory, memory copy,move, reverse and reservevia function calls.
 * There is also a globally allocated buffer array used for manipulation. 
 *
 * @author Sharath chandran
 * @date Oct 9 2020
 *
 */
#include <stdint.h>
#include <stdlib.h>
#include "memory.h"
#include "platform.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

// Memory copy Data courruption may occur
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length)
{
	//copy source to destinatio
	for ( int i = 0; i < length; i++ )
		{
			*dst = *src;
			src++;
			dst++;
		}	
	//reset source and destination memory location
	dst = dst - length;
	src = src - length;
	return dst;	
}

// Memory copy without data corruption
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length)
{
	uint8_t *src_cpy;
	//reserve a temporary memory location to store dara
	src_cpy = (uint8_t*) reserve_words( length );
	//copy source data to temporary memory location
	for ( int i = 0; i < length; i++ )
		{
			*src_cpy = *src;
			src_cpy++;
			src++;
		}	
	src_cpy = src_cpy - length;
	//copy the data in temporary memory to destination location
	for ( int j = 0; j < length; j++ )
		{
			*dst = *src_cpy;
			src_cpy++;
			dst++;
		}	
	src_cpy = src_cpy - length;
	//free the temporary memory location
	free_words((uint32_t *)src_cpy);
	//reset source and destination memory location
	dst = dst - length;
	src = src - length;
	return dst;	
}

//set the given data to the memory location till the given length
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value)
{
	for ( int i = 0; i < length; i++ )
		{
			*src = value;
			src++;
		}
	src = src - length;
	return src;
}

//set the memory location to zero till the given length
uint8_t * my_memzero(uint8_t * src, size_t length)
{
	for ( int i = 0; i < length; i++ )
		{
			*src = 0;
			src++;
		}
	src = src - length;
	return src;
}

//reverse the data in the given memory location
uint8_t * my_reverse(uint8_t * src, size_t length)
{
	uint8_t *src_cpy;
	//reserve a temporary memory location to give length
	src_cpy = (uint8_t*) reserve_words( length );
	//copy the source data to the temporary location
	for ( int i = 0; i < length; i++ )
		{
			*src_cpy = *src;
			src_cpy++;
			src++;
		}	
	//reset source memory to initial value
	src = src - length;
	src_cpy = src_cpy - 1;
	//copy the data in temporary location to source in reverse order
	for ( int j = 0; j < length; j++ )
		{
			*src = *src_cpy;
			src_cpy--;
			src++;
		}	
	//reset temporary memory
	src_cpy = src_cpy + 1;
	//free the temporary memory
	free_words((uint32_t *)src_cpy);
	//reset source memory
	src = src - length;
	return src;	
}
//function to reserve a memory location to a given length
int32_t * reserve_words(size_t length)
{
	int32_t * returnPtr;
	returnPtr = (int32_t *) malloc((sizeof(size_t)*length));
	if ( returnPtr == 0)
	{
		return NULL;
	}
	else
	{
		return returnPtr;
	}
}

// free the reserve memory
void free_words(uint32_t * src)
{
	free(src);
}

