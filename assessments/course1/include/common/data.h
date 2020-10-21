/***
* @file data.h
* @brief Header file for data.c
* 
* @author Hemalatha
* @date October 13, 2020
*****/



#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>

/**
* @brief Converts data from ASCII represented string into an integer type
* 
* This function converts data from a ASCII string into an integer type and returns the 
* length of the converted c-string
*
* @param ptr pointer to string that needs to be converted
* @param digits number of digits in your character set
* @param base base you wish to convert to
*
* @return length of converted data including NULL terminator
**/
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

/**
* @brief Converts data from a standard integer type into an ASCII string.
* 
* This function converts data from a standard integer type into an ASCII string and returns the 
* length of the converted c-string
*
* @param data no. that needs to be converted
* @param ptr converted string is copied to this pointer
* @param base base you wish to convert to
*
* @return length of converted data including NULL terminator
**/
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);


#endif
