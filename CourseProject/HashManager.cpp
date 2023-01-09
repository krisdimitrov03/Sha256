#include <iostream>
#include <bitset>
#include "HashManager.h"
#include "ConsoleWriter.h"

const int MAX_BINARY_SIZE = 8;

int binaryLen(int number) {
	int result = 0;
	while (number > 0)
	{
		number /= 2;
		result++;
	}
	return result;
}

int* binary(int number) {
	int result[MAX_BINARY_SIZE]{ 0 };
	int i = 0;
	while (number > 0)
	{
		result[MAX_BINARY_SIZE - (i++) - 1] = number % 2;
		number /= 2;
	}

	return result;
}

int* bigBinary(int number) {
	int length = binaryLen(number);
	int* result = new int[length];
	for (int i = length - 1; i >= 0; i--)
	{
		result[i] = number % 2;
		number /= 2;
	}
	return result;
}

int* preProcessInput(const char* message, int length) {
	int size = 512;
	while (length * 8 > size - 65)
		size *= 2;

	int* bits = new int[size] {0};
	int i = 0;
	for (; i < length; i++)
	{
		int* binaryNum = binary(message[i]);
		for (int j = 0; j < MAX_BINARY_SIZE; j++)
			bits[i * 8 + j] = binaryNum[j];
	}
	bits[(i++) * 8] = 1;

	int* lengthInBinary = bigBinary(length * 8);
	int lengthInBinaryLength = binaryLen(length * 8);
	for (int i = 0; i < lengthInBinaryLength; i++)
	{
		bits[size - i - 1] = lengthInBinary[lengthInBinaryLength - i - 1];
	}

	return bits;
}

int** splitInput(const int* input) {
	
}

char* hash(const char* message, int length) {
	int* input = preProcessInput(message, length);
	int** words = splitInput(input);



	return new char[5];
}

char* dehash(const char* hashedMessage, int length) {
	return new char[5];
}