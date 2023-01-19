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