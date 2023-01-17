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
int** modifyAtoHConstants(int** chunk, int** kConstants, int** hConstants);
int** sumOldAndNewConstants(int** oldConstants, int** newConstants);
const char* getHash(int** binaryHash);

//vremenna funkciq
//void print(int* arr, int length) {
//	for (int i = 0; i < length; i++)
//	{
//		std::cout << arr[i];
//	}
//	std::cout << std::endl;
//}

const char* hash(const char* message) {
	int length = 0;
	while (message[length++] != '\0');
	length--;
	int** kConstants = generateKConstants();
	int inputSize = 0;
	int* input = preProcessInput(message, length, inputSize);
	int** words = splitInput(input, inputSize);

	int** chunk = getChunk(words);
	/*for (int i = 0; i < 16; i++)
	{
		print(chunk[i], 32);
	}*/

	int** hConstants = generateAtoHConstants();

	int** modifiedConstants = modifyAtoHConstants(chunk, kConstants, hConstants);
	/*for (int i = 0; i < 8; i++)
	{
		print(modifiedConstants[i], 32);
	}*/

	/*print(hConstants[0], 32);
	print(modifiedConstants[0], 32);
	printl("--------------------------------");
	print(sum(hConstants[0], modifiedConstants[0]), 32);*/

	int** binaryHash = sumOldAndNewConstants(hConstants, modifiedConstants);

	/*for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			std::cout << binaryHash[i][j];
		}
		std::cout << std::endl;
	}*/

	return getHash(binaryHash);
}

const char* dehash(const char* hashedMessage, int length) {
	return "Not Implemented";
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
	int* primes = getFirstNPrimes(64);

	for (int i = 0; i < 64; i++)
	{
		long long constant = getConstantInDecimal(primes[i], "cbrt");
		result[i] = binary(constant, 32);
	}

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

int** modifyAtoHConstants(int** chunk, int** kConstants, int** hConstants) {
	int** result = new int* [MAX_WORD_BINARY_SIZE] {0};
	for (int i = 0; i < MAX_WORD_BINARY_SIZE; i++)
		result[i] = hConstants[i];

	for (int i = 0; i < 64; i++)
	{
		int* word = chunk[i];
		int* kConst = kConstants[i];

		int* leftE = rotR(result[4], 6);
		int* midE = rotR(result[4], 11);
		int* rightE = rotR(result[4], 25);
		int* sigma1 = xOr(leftE, midE, rightE);
		/*print(result[4], 32);
		printl("--");
		print(leftE, 32);
		print(midE, 32);
		print(rightE, 32);
		printl("--------------------------------");
		print(sigma1, 32);*/


		int* sigma0 = xOr(rotR(result[0], 2), rotR(result[0], 13), rotR(result[0], 22));
		int* choice = xOr(bAnd(result[4], result[5]), bAnd(bNot(result[4]), result[6]));
		int* majority = xOr(bAnd(result[0], result[1]), bAnd(result[0], result[2]), bAnd(result[1], result[2]));

		int* temp1 = sum(result[7], sigma1, choice, kConst, word);
		int* temp2 = sum(sigma0, majority);

		/*print("Sigma0: ");
		print(sigma0, 32);
		print(" Major: ");
		print(majority, 32);
		printl("        --------------------------------");
		print(" Temp2: ");

		print(temp2, 32);
		printl("");*/

		for (int i = 7; i > 0; i--)
			result[i] = result[i - 1];

		result[0] = sum(temp1, temp2);
		result[4] = sum(result[4], temp1);

		/*for (int i = 0; i < 8; i++)
		{
			print(result[i], 32);
		}*/
	}

	return result;
}

int** sumOldAndNewConstants(int** oldConstants, int** newConstants) {
	int** result = new int* [MAX_WORD_BINARY_SIZE];

	for (int i = 0; i < 8; i++)
		result[i] = sum(oldConstants[i], newConstants[i]);

	return result;
}

const char* getHash(int** binaryHash) {
	int resLen = (MAX_WORD_BINARY_SIZE / 4) * 8;
	char* result = new char[resLen + 1]{ '\0' };
	int counter = 0;

	for (int i = 0; i < 64; i += 8)
	{
		char* hexNum = hex(binaryHash[counter++]);
		for (int j = 0; j < 8; j++)
			result[j + i] = hexNum[j];
	}

	return result;
}