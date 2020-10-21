/**
* @file data.c
* @brief performs simple data manipulation
*
* @author Hemalatha
* @Date October 14, 2020
**/

#include "data.h"
#include "memory.h"
#include <math.h>
#include <stdio.h>

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
	int i=0;
	// Return 1 if data passed is zero
	if(data == 0)
	{
		ptr[i++]='0';
		ptr[i]='\0';
		return 1;
	}

	uint8_t negative = 0;

	//if data is negative, set the negative flag and make it a positive number
	if(data<0){
		negative = 1;
		data = -data;
	}

	//Converting integer to ascii
	while(data != 0){
		int rem = data % base;
		ptr[i++] = (rem>9) ? (rem -10) + 'a' : rem + '0';
		data/= base;
	}

	//Append a '-' if data is negative
	if(negative == 1)
		ptr[i++] = '-';


	//Null terminator
	ptr[i] = '\0';
	my_reverse(ptr, i);
	return i;

}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
	int i=1;
	uint8_t negative = 0;
	int num=0;
	//Check for negative number
	if(ptr[0] == '-')
		negative = 1;
	i = digits-1;

	//Negative number starts from ptr[1] whereas positive number starts from ptr[0]
	uint8_t condition = (negative==1) ? (1) :(0);

	
	int j=0;
	while(i>=condition)
	{
		int ch = (ptr[i]>= 'a' && ptr[i]<= 'e') ? (int)(ptr[i--] - 'a' + 10) : (int)(ptr[i--] -'0');
		num += (int)pow(base,j++) * ch;
	}

	return (negative==1) ? (num*-1) : num;
}





