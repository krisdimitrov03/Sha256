/**
*
* Solution to course project # 6
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Kristian Dimitrov
* @idnumber 8MI0600166
* @compiler VC
*
* <functions for input validation>
*
*/

#include "../include/validator.h"

//bool security::validateChar(char value)
//{
//	return value >= 0 || value < 128;
//}
//
//bool security::validateMessageLength(const char* message)
//{
//	int count = 0;
//	while (message[count++] != '\0');
//	count--;
//
//	return count < 1000 && count > 0;
//}

bool security::validateChar(char value)
{
	return value >= 0 || value < 128;
}

bool security::validateMessageLength(const char* message)
{
	int count = 0;
	while (message[count++] != '\0');
	count--;
	
	return count < 1000 && count > 0;
}
