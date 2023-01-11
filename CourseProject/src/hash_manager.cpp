#include <iostream>
#include <bitset>
#include "../include/hash_manager.h"
#include "../include/console_writer.h"
#include "../include/helper/size_constants.h"

char** generateConstants();
int* preProcessInput(const char* message, int length, int& destSize);
int** splitInput(const int* input, int size);
int** getChunk(int** words);
int** getKConstants(int** chunk, char** constants);
int** getHashInBinary(int** kConstants, int& binaryHashLength);
const char* hex(int** binaryHash, int binaryHashLength);

//help functions
int binaryLen(int number);
int* binary(int number);
int* bigBinary(int number);
int* xOr(int* num1, int* num2, int* num3);
int* rotR(int* bitSet, int repeat);
int* shR(int* bitSet, int repeat);
int* sum(int* num1, int* num2, int* num3, int* num4);

const char* hash(const char* message, int length) {
	int inputSize = 0;
	int* input = preProcessInput(message, length, inputSize);
	int** words = splitInput(input, inputSize);

	int** chunk = getChunk(words);
	char** hConstants = generateConstants();
	int** kConstants = getKConstants(chunk, hConstants);
	int binaryHashLength = 0;
	int** binaryHash = getHashInBinary(kConstants, binaryHashLength);

	//return "b94d27b9934d3e08a52e52d7da7dabfac484efe37a5380ee9088f7ace2efcde9";
	return hex(binaryHash, binaryHashLength);
}

const char* dehash(const char* hashedMessage, int length) {
	return "";
}

int* preProcessInput(const char* message, int length, int& destSize) {
	int size = 512;
	while (length * 8 > size - 65)
		size *= 2;

	destSize = size;

	int* bits = new int[size] {0};
	int i = 0;
	for (; i < length; i++)
	{
		int* binaryNum = binary(message[i]);
		for (int j = 0; j < MAX_LETTER_BINARY_SIZE; j++)
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

int** splitInput(const int* input, int size) {
	int** words = new int* [size];

	for (int i = 0; i < size / 32; i++) {
		words[i] = new int[32]{ 0 };
		for (int j = 0; j < 32; j++)
			words[i][j] = input[i * 32 + j];
	}

	return words;
}

char** generateConstants() {
	return new char* [6];
}

int** getChunk(int** words) {
	int** result = new int* [MAX_CHUNK_SIZE];

	for (int i = 0; i < 16; i++)
		result[i] = words[i];

	for (int i = 0; i < 48; i++)
	{
		result[i + 16] = sum(
			result[i],
			xOr(rotR(result[i + 1], 7), rotR(result[i + 1], 18), shR(result[i + 1], 3)),
			result[i + 9],
			xOr(rotR(result[i + 14], 17), rotR(result[i + 14], 19), shR(result[i + 14], 10))
		);
	}

	return result;
}

int** getKConstants(int** chunk, char** constants) {
	return new int* [5];
}

int** getHashInBinary(int** kConstants, int& binaryHashLength) {
	return new int* [5];
}

const char* hex(int** binaryHash, int binaryHashLength) {
	return "";
}

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
	int result[MAX_LETTER_BINARY_SIZE]{ 0 };
	int i = 0;
	while (number > 0)
	{
		result[MAX_LETTER_BINARY_SIZE - (i++) - 1] = number % 2;
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

int* xOr(int* num1, int* num2, int* num3) {
	int* result = new int[MAX_WORD_BINARY_SIZE];
	for (int i = 0; i < MAX_WORD_BINARY_SIZE; i++)
		result[i] = num1[i] ^ num2[i] ^ num3[i];
	return result;
}

int* rotR(int* bitSet, int repeat) {
	for (int i = 0; i < repeat; i++)
	{
		int temp = bitSet[MAX_WORD_BINARY_SIZE - 1];
		for (int j = MAX_WORD_BINARY_SIZE - 1; j > 0; j--)
			bitSet[j] = bitSet[j - 1];
		bitSet[0] = temp;
	}
	return bitSet;
}

int* shR(int* bitSet, int repeat) {
	for (int i = 0; i < repeat; i++)
	{
		for (int j = MAX_WORD_BINARY_SIZE - 1; j > 0; j--)
			bitSet[j] = bitSet[j - 1];
		bitSet[0] = 0;
	}
	return bitSet;
}

int* sum(int* num1, int* num2, int* num3, int* num4) {
	return new int[6];
}