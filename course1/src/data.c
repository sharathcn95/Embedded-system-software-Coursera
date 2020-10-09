#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
 	uint32_t i = 0;
    uint8_t length = 0;
    uint32_t dec=0,rem;
    unsigned int temp;
    //printf("\ndata %d\n", data);
	if (data < 0)
    {
    	temp = -1 * data;
    }
    else
    {
		temp = data;
	}

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

	while(dec != 0)
	{
    	rem = dec%10;
    	dec = dec/10;
    	*ptr = (rem + 48);
    	length++;
    	ptr = ptr + 1;
	}
	if(data < 0)
	{
		*ptr = 45;
		ptr = ptr + 1;
		length++;
	}
	*ptr = '\0';
	length++;
	ptr = ptr - (length);
	//printf("\n to my reverse\n");
	my_reverse(ptr, length);
	printf(" inside itoa %d ",*ptr);
	//printf("\n %s \n",ptr);
	return length;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
	int32_t value = 0, base_value = 0 ,base_rev = 0, rem,div;
	ptr = ptr-1;
	//printf("\n %d \n",*ptr);
	if (*ptr  == 45)
	{
		ptr = ptr + 1;
		//printf("\n inside  \n");
		digits = digits - 1;
	}
	//printf("\n %d \n",digits);
	for (uint32_t i = 0; i < digits - 1; i++)
	{
		value = value*10 + (*ptr - 48);
		ptr = ptr + 1;
		//printf("\n %d\n", value); 
	}
	//printf("\n %d\n", value); 
	ptr = ptr - (digits);
	if(base != 10)
	{
		while(value != 0)
		{
			rem = value % base;
			//printf("\n %d\n", rem);
			value = value / base;
			base_rev = base_rev*10 + rem; 
			//printf("\n %d\n", base_value); 
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
	//printf("\n %d\n", base_value); 
	if (*ptr == 45 )
	{
		base_value = -1*base_value;
	}
	return base_value;
}
