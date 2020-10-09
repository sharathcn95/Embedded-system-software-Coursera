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
 * @file Stats.c
 * @brief performs basic statistics on given data array
 *
 * This function calulates Maximum, Minimum, Median, Mean and median
 * this function also performs sort the array in desending order
 *
 * @author Sharath Chandran
 * @date Oct 9 2020
 *
 */



#include "stats.h"
#include "platform.h"


/* Add other Implementation File Code Here */
//Print the Given array for debug
void print_array(unsigned char *a, int count)
 {
 	//check fro the debug macro
 	if(DEBUG){
 	PRINTF("\ntest[%d] = \n{", count);
 	int i;  
		for ( i = 0; i < count; i++)
			{
				PRINTF("\t%d", a[i]);
				if(( ( i + 1) % 5) == 0)
					PRINTF("\n");
	        }
	PRINTF("\t}\n");
	}
 }
 //sort the array in decending order
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
 
 //find the median of the given array
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
 
 //calcuate the mean value
int find_mean(unsigned char *a, int count)
 {
   int i,sum = 0;

    for(i = 0; i < count; i++) 
        {
            sum+=a[i];
        }

   return (sum / count);
 }
 
 //find the maximum
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

//find the minimum
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

//print the result to the screen
void print_statistics(unsigned char *a, int count)
{
    int max = 0, min = 0, median = 0, mean = 0;
    max = find_maximum(a, count);
    min = find_minimum(a, count);
    median = find_median(a,count);
    mean = find_mean(a, count);
    PRINTF("\nmaximum = %d\n", max);
    PRINTF("\nminimum = %d\n", min);
    PRINTF("\nmean = %d\n", mean);
    PRINTF("\nmedian = %d\n", median);
}
