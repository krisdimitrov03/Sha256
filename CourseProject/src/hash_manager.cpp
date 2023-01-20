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
* <hash function and its helpers (all the stages of the algorithm)>
*
*/

#include <iostream>
#include "../include/hash_manager.h"
#include "../include/math_operator.h"
#include "../include/helper/size_constants.h"

int** generateAtoHConstants();
int** generateKConstants();
int* preProcessInput(const char* message, int length, int& destSize);
int** splitInput(const int* input, int size);
int** getChunk(int** words);
int** modifyAtoHConstants(int** chunk, int** kConstants, int** hConstants);
int** sumOldAndNewConstants(int** oldConstants, int** newConstants);
const char* getHash(int** binaryHash);

const char* sha256::hash(const char* message) {
	int length = 0;
	while (message[length++] != '\0');
	length--;
	int** kConstants = generateKConstants();
	int** hConstants = generateAtoHConstants();
	int inputSize = 0;
	int* entireInput = preProcessInput(message, length, inputSize);

	for (int i = 0; i < inputSize / PRE_PROCESS_INPUT_START_SIZE; i++)
	{
		int* input = new int[PRE_PROCESS_INPUT_START_SIZE];

		for (int j = 0; j < PRE_PROCESS_INPUT_START_SIZE; j++)
			input[j] = entireInput[j + i * PRE_PROCESS_INPUT_START_SIZE];

		int** words = splitInput(input, PRE_PROCESS_INPUT_START_SIZE);
		int** chunk = getChunk(words);
		int** modifiedConstants = modifyAtoHConstants(chunk, kConstants, hConstants);
		hConstants = sumOldAndNewConstants(hConstants, modifiedConstants);
	}

	return getHash(hConstants);
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
		int* binaryNum = math::binary(message[i], MAX_LETTER_BINARY_SIZE);
		for (int j = 0; j < MAX_LETTER_BINARY_SIZE; j++)
			bits[i * 8 + j] = binaryNum[j];
	}
	bits[(i++) * 8] = 1;

	int* lengthInBinary = math::binary(length * MAX_LETTER_BINARY_SIZE);
	int lengthInBinaryLength = math::binaryLen(length * MAX_LETTER_BINARY_SIZE);
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
		if (math::isPrime(i)) {
			long long constant = math::getConstantInDecimal(i, "sqrt");
			result[count++] = math::binary(constant, MAX_WORD_BINARY_SIZE);
		}

	return result;
}

int** generateKConstants() {
	int** result = new int* [MAX_WORD_BINARY_SIZE] {0};
	int* primes = math::getFirstNPrimes(64);

	for (int i = 0; i < 64; i++)
	{
		long long constant = math::getConstantInDecimal(primes[i], "cbrt");
		result[i] = math::binary(constant, 32);
	}

	return result;
}

int** getChunk(int** words) {
	int** result = new int* [MAX_CHUNK_SIZE];

	for (int i = 0; i < FIRST_WORDS_COUNT; i++)
		result[i] = words[i];

	for (int i = 0; i < MAX_CHUNK_SIZE - FIRST_WORDS_COUNT; i++)
	{
		result[i + FIRST_WORDS_COUNT] = math::sum(
			result[i],
			math::xOr(math::rotR(result[i + 1], 7), math::rotR(result[i + 1], 18), math::shR(result[i + 1], 3)),
			result[i + 9],
			math::xOr(math::rotR(result[i + 14], 17), math::rotR(result[i + 14], 19), math::shR(result[i + 14], 10))
		);
	}

	return result;
}

int** modifyAtoHConstants(int** chunk, int** kConstants, int** hConstants) {
	int** result = new int* [MAX_WORD_BINARY_SIZE] {0};
	for (int i = 0; i < MAX_WORD_BINARY_SIZE; i++)
		result[i] = hConstants[i];

	for (int i = 0; i < 64; i++)
	{
		int* word = chunk[i];
		int* kConst = kConstants[i];
		int* sigma1 = math::xOr(math::rotR(result[4], 6), math::rotR(result[4], 11), math::rotR(result[4], 25));
		int* sigma0 = math::xOr(math::rotR(result[0], 2), math::rotR(result[0], 13), math::rotR(result[0], 22));
		int* choice = math::xOr(math::bAnd(result[4], result[5]), math::bAnd(math::bNot(result[4]), result[6]));
		int* majority = math::xOr(math::bAnd(result[0], result[1]), math::bAnd(result[0], result[2]), math::bAnd(result[1], result[2]));

		int* temp1 = math::sum(result[7], sigma1, choice, kConst, word);
		int* temp2 = math::sum(sigma0, majority);

		for (int i = 7; i > 0; i--)
			result[i] = result[i - 1];

		result[0] = math::sum(temp1, temp2);
		result[4] = math::sum(result[4], temp1);
	}

	return result;
}

int** sumOldAndNewConstants(int** oldConstants, int** newConstants) {
	int** result = new int* [MAX_WORD_BINARY_SIZE];

	for (int i = 0; i < 8; i++)
		result[i] = math::sum(oldConstants[i], newConstants[i]);

	return result;
}

const char* getHash(int** binaryHash) {
	char* result = new char[HASH_LENGTH + 1]{ '\0' };
	int counter = 0;

	for (int i = 0; i < HASH_LENGTH; i += 8)
	{
		char* hexNum = math::hex(binaryHash[counter++]);
		for (int j = 0; j < 8; j++)
			result[j + i] = hexNum[j];
	}

	return result;
}