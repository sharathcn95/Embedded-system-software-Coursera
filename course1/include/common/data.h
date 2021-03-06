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
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __DATA_H__
#define __DATA_H__
/**
 * @brief This function takes the integer value of given base and return ascii string
 *
 * This function takes the integer data and the base value and convert into standerd ASCII string 
 * and return the length of string
 *
 * @param data given integer
 * @param ptr pointer to store ASCII string 
 * @param base base of integer
 *
 * @return length of string
 */
 uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);
 
 
 /**
 * @brief This function takes the ASCII String and return integer value of given base
 *
 * This function takes the ASCII String and base value and convert into integer value of given base 
 *
 * @param digits length of string
 * @param ptr pointer to store ASCII string 
 * @param base base of integer
 *
 * @return integer
 */
 int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);
 #endif
