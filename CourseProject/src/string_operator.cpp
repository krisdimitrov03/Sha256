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
* <functions for string (char*) operations>
*
*/

#include "../include/string_operator.h"

const char* string::concat(const char* leftStr, const char* rightStr) {
	int leftLen = 0, rightLen = 0;
	while (leftStr[leftLen++] != '\0');
	while (rightStr[rightLen++] != '\0');
	leftLen--;
	rightLen--;

	char* result = new char[leftLen + rightLen + 1] {'\0'};

	for (int i = 0; i < leftLen; i++)
		result[i] = leftStr[i];
	for (int i = 0; i < rightLen; i++)
		result[i + leftLen] = rightStr[i];

	return (const char*)result;
}

const char* string::concat(const char* leftStr, const char* midStr, const char* rightStr) {
	return concat(concat(leftStr, midStr), rightStr);
}

const char* string::getHashSubstring(const char* str, int length)
{
	char* result = new char[length + 1] {'\0'};
	int index = 0;
	while (str[index] != '\0') {
		if (str[index] == ':') {
			index += 2;
			break;
		}
		index++;
	}
	int resultIndex = 0;
	while (str[index] != '\0')
		result[resultIndex++] = str[index++];

	return result;
}

const char* string::getMessageSubstring(const char* str)
{
	int length = 0;
	while (str[length++] != ':');
	char* result = new char[length] {'\0'};

	for (int i = 0; i < length - 2; i++)
		result[i] = str[i];

	return result;
}
