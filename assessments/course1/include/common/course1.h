/**
@file course1.h
@brief header file for course1.c file

This file has prototypes for final course assessment functions

@author Hemalatha
@date October 13, 2020
**/

#ifndef __COURSE1_H__
#define __COURSE1_H__

#include <stdint.h>

#define DATA_SET_SIZE_W (10)
#define MEM_SET_SIZE_B  (32)
#define MEM_SET_SIZE_W  (8)
#define MEM_ZERO_LENGTH (16)
#define BASE_10 (10)
#define BASE_16 (16)
#define TEST_MEMMOVE_LENGTH (16)
#define TEST_ERROR          (1)
#define TEST_NO_ERROR       (0)
#define TESTCOUNT (8)

/**
* @brief function to call remaining functions
*
* This function calls the functions test_data1(), test_data2(), test_memmove1(), test_memmove2(), * test_memmove3(), test_memcopy(), test_memset(), and test_reverse().
*
* @return void
**/
void course1();

/**
* @brief function to test
*
* This function tests atoi and itoa conversions for you
*
* @return int8_t
**/
int8_t test_data2();

/**
* @brief function to test
*
* This function tests atoi and itoa conversions for you
*
* @return int8_t
**/
int8_t test_data2();

/**
* @brief function to test
*
* This function tests non-overlapped memmove
*
* @return int8_t
**/
int8_t test_memmove1();

/**
* @brief function to test
*
* This function tests overlapped memmove where there is overlap of the end of the destination and * start of the source regions.
*
* @return int8_t
**/
int8_t test_memmove2();

/**
* @brief function to test
*
* This function tests overlapped memmove where there is overlap of the start of destination and end of the source regions.
*
* @return int8_t
**/
int8_t test_memmove3();

/**
* @brief function to test
*
* This function tests memcopy
*
* @return int8_t
**/
int8_t test_memcopy();

/**
* @brief function to test
*
* This function tests memset and memzero
*
* @return int8_t
**/
int8_t test_memset();
/**
* @brief function to test
*
* This function tests reverse
*
* @return int8_t
**/
int8_t test_reverse();


#endif
