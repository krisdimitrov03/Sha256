#include <iostream>
#include "../include/math_operator.h"
#include "../include/helper/size_constants.h"

bool isPrime(int number) {
	if (number == 0 || number == 1)
		return false;

	for (int i = 2; i <= number / 2; ++i)
		if (number % i == 0)
			return false;
}

long long getConstantInDecimal(int num, const char* rootType) {
	double root;
	if (rootType == "sqrt")
		root = sqrt(num);
	else
		root = cbrt(num);

	root -= (int)root;

	return (long long)(root * pow(2, 32));
}

int binaryLen(long long number) {
	int result = 0;
	while (number > 0)
	{
		number /= 2;
		result++;
	}
	return result;
}

int* binary(long long number, int padSize) {
	int* result;
	int resultLength = 0;
	if (padSize != DEFAULT_VALUE)
		resultLength = padSize;
	else
		resultLength = binaryLen(number);

	result = new int[resultLength] {0};

	int i = resultLength - 1;
	while (number > 0)
	{
		result[i--] = number % 2;
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