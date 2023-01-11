#include <iostream>
#include <bitset>
#include "../include/hash_manager.h"
#include "../include/console_writer.h"
#include "../include/math_operator.h"
#include "../include/helper/size_constants.h"

int** generateAtoHConstants();
int** generateKConstants();
int* preProcessInput(const char* message, int length, int& destSize);
int** splitInput(const int* input, int size);
int** getChunk(int** words);
int** getHashInBinary(int** kConstants, int& binaryHashLength);
const char* hex(int** binaryHash, int binaryHashLength);


const char* hash(const char* message, int length) {
	int inputSize = 0;
	int* input = preProcessInput(message, length, inputSize);
	int** words = splitInput(input, inputSize);

	//int** chunk = getChunk(words);
	int** hConstants = generateAtoHConstants();
	int** kConstants = generateKConstants();
	/*for (int i = 0; i < 64; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			std::cout << kConstants[i][j];
		}
		std::cout << std::endl;
	}*/
	int binaryHashLength = 0;
	int** binaryHash = getHashInBinary(kConstants, binaryHashLength);

	//return "b94d27b9934d3e08a52e52d7da7dabfac484efe37a5380ee9088f7ace2efcde9";
	return hex(binaryHash, binaryHashLength);
}

const char* dehash(const char* hashedMessage, int length) {
	return "";
}

int* preProcessInput(const char* message, int length, int& destSize) {
	int size = PRE_PROCESS_INPUT_START_SIZE;
	while (length * MAX_LETTER_BINARY_SIZE > size - 65)
		size *= 2;

	destSize = size;

	int* bits = new int[size] {0};
	int i = 0;
	for (; i < length; i++)
	{
		int* binaryNum = binary(message[i], MAX_LETTER_BINARY_SIZE);
		for (int j = 0; j < MAX_LETTER_BINARY_SIZE; j++)
			bits[i * 8 + j] = binaryNum[j];
	}
	bits[(i++) * 8] = 1;

	int* lengthInBinary = binary(length * MAX_LETTER_BINARY_SIZE);
	int lengthInBinaryLength = binaryLen(length * MAX_LETTER_BINARY_SIZE);
	for (int i = 0; i < lengthInBinaryLength; i++)
	{
		bits[size - i - 1] = lengthInBinary[lengthInBinaryLength - i - 1];
	}

	return bits;
}

int** splitInput(const int* input, int size) {
	int** words = new int* [size];

	for (int i = 0; i < size / MAX_WORD_BINARY_SIZE; i++) {
		words[i] = new int[MAX_WORD_BINARY_SIZE] { 0 };
		for (int j = 0; j < MAX_WORD_BINARY_SIZE; j++)
			words[i][j] = input[i * MAX_WORD_BINARY_SIZE + j];
	}

	return words;
}

int** generateAtoHConstants() {
	int** result = new int* [MAX_WORD_BINARY_SIZE];

	for (int i = 2, count = 0; count < H_CONSTANTS_COUNT; i++)
		if (isPrime(i)) {
			long long constant = getConstantInDecimal(i, "sqrt");
			result[count++] = binary(constant, MAX_WORD_BINARY_SIZE);
		}

	return result;
}

int** generateKConstants() {
	int** result = new int* [MAX_WORD_BINARY_SIZE] {0};

	//Solve Problem

	/*for (int i = 2, count = 0; count < K_CONSTANTS_COUNT; i++)
		if (isPrime(i)) {
			long long constant = getConstantInDecimal(i, "cbrt");
			result[count++] = binary(constant, MAX_WORD_BINARY_SIZE);
		}*/

	return result;
}

int** getChunk(int** words) {
	int** result = new int* [MAX_CHUNK_SIZE];

	for (int i = 0; i < FIRST_WORDS_COUNT; i++)
		result[i] = words[i];

	for (int i = 0; i < MAX_CHUNK_SIZE - FIRST_WORDS_COUNT; i++)
	{
		result[i + FIRST_WORDS_COUNT] = sum(
			result[i],
			xOr(rotR(result[i + 1], 7), rotR(result[i + 1], 18), shR(result[i + 1], 3)),
			result[i + 9],
			xOr(rotR(result[i + 14], 17), rotR(result[i + 14], 19), shR(result[i + 14], 10))
		);
	}

	return result;
}

int** getHashInBinary(int** kConstants, int& binaryHashLength) {
	return new int* [5];
}

const char* hex(int** binaryHash, int binaryHashLength) {
	return "";
}