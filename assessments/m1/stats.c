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
 * @file stats.c 
 * @brief Statistical operations on an array of numbers
 *
 * 
 *
 * @author C.Hemalatha
 * @date 08-09-2020
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE 40

int main()
{

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
	sort_array(test);
	print_statistics(test);

}

void print_statistics(unsigned char array[])
{
	printf("Array elements are: ");
	print_array(array);
	printf("\nStatistics of the the given array:");
	printf("\nMinimum : %d",find_minimum(array));
	printf("\nMaximum : %d",find_maximum(array));
	printf("\nMean 	  : %d", find_mean(array));
	printf("\nMedian  : %d\n", find_median(array));
}

	
void print_array(unsigned char array[])
{
	for(int i=0;i<SIZE;i++)
		printf("%d ",array[i]);
}

unsigned char find_median(unsigned char array[])
{
	int median=((SIZE%2)==0)?((SIZE/2)-1):(((SIZE+1)/2)-1);
	return array[median];
}

	
unsigned char find_mean(unsigned char array[])
{
	int sum=0;
	for(int i=0;i<SIZE;i++)
		sum+=array[i];
	return (sum/SIZE);
}

	
unsigned char find_maximum(unsigned char array[])
{
	unsigned char max=array[0];
	for(int i=1;i<SIZE;i++)
	{
		if(max<array[i])
			max=array[i];
	}
	return max;
}
	
unsigned char find_minimum(unsigned char array[])
{
	unsigned char min=array[0];
	for(int i=1;i<SIZE;i++)
	{
		if(min>array[i])
			min=array[i];
	}
	return min;
}	
void sort_array(unsigned char *array)
{
	int i,j;
	unsigned char temp;
	for(i=0;i<SIZE;i++)
	{
		for(j=i+1;j<SIZE;j++)
		{
			if(array[i]<array[j])
			{
				temp=array[i];
				array[i]=array[j];
				array[j]=temp;
			}
		}
	}
}
