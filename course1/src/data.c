/**
 * @file data.c
 * @brief performs Integer to ACSII and vice vers
 *
 * This function find the ACSII value to given integer of any base.
 * It can also find the Integer value of given base from the ACSII string
 *
 * @author Sharath Chandran
 * @date Oct 9 2020
 *
 */
 
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>
#include "platform.h"
#include <stddef.h>

//Integer to ACSII funtion 
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
 	uint32_t i = 0;
    uint8_t length = 0;
    uint32_t dec=0,rem;
    unsigned int temp;
    //check for negative interger if then conver it to positive integer
	if (data < 0)
    {
    	temp = -1 * data;
    }
    else
    {
		temp = data;
	}
	//check for decimal value, if no convert it into decimal value
	if(base != 10)
	{
		while(temp != 0)
		{
    		rem = temp%10;
    		temp = temp/10;
    		dec = dec + (rem *pow(base,i)) ;
    		i = i + 1;
		}
	}	
	else
	{
    	dec = temp;
	}
	//Convert the decimal value to ASCII string
	while(dec != 0)
	{
    	rem = dec%10;
    	dec = dec/10;
    	*ptr = (rem + 48);
    	length++;
    	ptr++;
	}
	//if negative indeger add ASCII value 45 to the ASCII string
	if(data < 0)
	{
		*ptr = 45;
		ptr++;
		length++;
	}
	*ptr = '\0';
	length++;
	//Reset the ASCII memory to initial value
	ptr = ptr - (length-1);
	//reverse the string
	my_reverse(ptr, length-1);
	return length;
}

//ACSII to Integer of given base
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
	int32_t value = 0, base_value = 0 ,base_rev = 0, rem,div;
	//check for negative Value
	if (*ptr  == 45)
	{
		ptr++;
		digits = digits - 1;
	}
	//convert the ACSII value to Decimal value
	for (uint32_t i = 0; i < digits - 1; i++)
	{
		value = value*10 + (*ptr - 48);
		ptr++;
	}
	//Reset the ACSII memory location
	ptr = ptr - (digits);
	//convert the Decimal value to integer of given base
	if(base != 10)
	{
		while(value != 0)
		{
			rem = value % base;
			value = value / base;
			base_rev = base_rev*10 + rem; 
		}
		while(base_rev != 0)
		{
			div = base_rev % 10;
			base_rev = base_rev / 10;
			base_value = base_value*10 + div;
		}
	}
	else
	{
		base_value = value;
	}
	//convert it into negative number if negative ACSII value if found
	if (*ptr == 45 )
	{
		base_value = -1*base_value;
	}
	return base_value;
}
