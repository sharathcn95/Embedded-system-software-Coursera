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
#ifndef __STATS_H__
#define __STATS_H__
#if defined (VERBOSE)
#define DEBUG (1)
#else
#define DEBUG (0)
#endif
/* Add Your Declarations and Function Comments here */ 

/**
 * @brief Given an array of data and a length, prints the array to the screen
 *
 * this function takes an input array and it's length and prints the array to the screen.
 *
 * @param a input array
 * @param count length of array
 */
void print_array(unsigned char *a, int count);

/**
 * @brief Given an array of data and a length, sorts the array from largest to smallest. 
 *
 * this function takes an input array and sort the array from the largest to the smallest.The zeroth Element is the largest value, and the last element (count-1) is the smallest value  
 *
 * @param a input array
 * @param count length of array
 */
void sort_array(unsigned char *a, int count);

/**
 * @brief Given an array of data and a length, returns the median value.
 *
 * this function takes an input array and returns the median of the array. this function calls the sort_array() fuction before calculating the median.
 *
 * @param a input array
 * @param count length of array
 *
 * @return the median value.
 */
float find_median(unsigned char *a, int count);

/**
 * @brief Given an array of data and a length, returns the mean.
 *
 * this function takes an input array and returns the mean value
 *
 * @param a input array
 * @param count length of array
 *
 * @return the mean value.
 */
int find_mean(unsigned char *a, int count);

/**
 * @brief Given an array of data and a length, returns the minimum.
 *
 * this function takes an input array and returns the minimum value
 *
 * @param a input array
 * @param count length of array
 *
 * @return the minimum value.
 */
int find_minimum(unsigned char *a, int count);

/**
 * @brief Given an array of data and a length, returns the maximum.
 *
 * this function takes an input array and returns the maximum value
 *
 * @param a input array
 * @param count length of array
 *
 * @return the maximum value.
 */
int find_maximum(unsigned char *a, int count);

/**
 * @brief A function that prints the statistics of an array.
 *
 * this function takes an input array and prints the statistics of an array including minimum, maximum, mean, and median.
 *
 * @param a input array
 * @param count length of array
 *
 */
void print_statistics(unsigned char *a, int count);
#endif /* __STATS_H__ */
