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
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */



#include <stdio.h>
#include "stats.h"


/* Add other Implementation File Code Here */
void print_array(unsigned char *a, int count)
 {
 	if(DEBUG){
 	printf("\ntest[%d] = \n{", count);
 	int i;  
		for ( i = 0; i < count; i++)
			{
				printf("\t%d", a[i]);
				if(( ( i + 1) % 5) == 0)
					printf("\n");
	        }
	printf("}\n");
	}
 }
void sort_array(unsigned char *a, int count)
 {
    int i, j, temp;
        for (i = 0; i < count; ++i) 
        {

            for (j = i + 1; j < count; ++j)
            {
 
                if (a[i] < a[j]) 
                {
 
                    temp =  a[i];
                    a[i] = a[j];
                    a[j] = temp;
 
                }
 
            }
        }
 }
float find_median(unsigned char *a, int count)
 {
    int median=0;
    sort_array(a, count);
    // if number of elements are even
    if(count%2 == 0)
        {
             median = (a[(count-1)/2] + a[count/2])/2.0;
        }
     // if number of elements are odd
    else
        {
            median = a[count/2];
        }
    return median; 
 }
int find_mean(unsigned char *a, int count)
 {
   int i,sum = 0;

    for(i = 0; i < count; i++) 
        {
            sum+=a[i];
        }

   return (sum / count);
 }
int find_minimum(unsigned char *a, int count)
{
  int min = a[0];
  int i = 0;
    for(i = 1; i < count; i++)
        {
            if(min >= a[i])
	        min = a[i];      
        }
  return min;
}
int find_maximum(unsigned char *a, int count)
{
  int max = 0;
  int i = 0;
    for(i = 1; i < count; i++)
        {  
	        if(max <= a[i])
            max = a[i];       
        }
  return max;
}
void print_statistics(unsigned char *a, int count)
{
    int max, min, median, mean;
    max = find_maximum(a, count);
    min = find_minimum(a, count);
    median = find_median(a,count);
    mean = find_mean(a, count);
    printf("\nmaximum = %d\n", max);
    printf("\nminimum = %d\n", min);
    printf("\nmean = %d\n", mean);
    printf("\nmedian = %d\n", median);
}
