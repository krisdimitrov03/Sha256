#include "../include/validator.h"

//bool security::validateChar(char value) {
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
