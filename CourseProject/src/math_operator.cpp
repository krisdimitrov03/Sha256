#include <iostream>
#include "../include/math_operator.h"
#include "../include/helper/size_constants.h"
#include "../include/helper/hex_constants.h"

bool isPrime(int number) {
	if (number == 0 || number == 1)
		return false;

	for (int i = 2; i <= number / 2; ++i)
		if (number % i == 0)
			return false;
}

int* getFirstNPrimes(int count) {
	int* result = new int[count];

	for (int num = 2, i = 0; i < count; num++)
		if (isPrime(num))
			result[i++] = num;

	return result;
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

char* hex(int* binary) {
	char* result = new char[(MAX_WORD_BINARY_SIZE / 4) + 1]{ '\0' };
	int counter = 0;

	for (int i = 0; i < MAX_WORD_BINARY_SIZE; i += 4)
	{
		int fourBitNum[4] = { binary[i], binary[i + 1], binary[i + 2], binary[i + 3] };
		int decimalNum = decimal(fourBitNum, 4);

		result[counter++] = HEX_VALUES[decimalNum];
	}

	return result;
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

int decimal(int* number, int length) {
	int result = 0;

	for (int i = 0; i < length; i++)
	{
		result += number[length - i - 1] * pow(2, i);
	}

	return result;
}

int* xOr(int* num1, int* num2, int* num3) {
	return xOr(xOr(num1, num2), num3);
}

int* xOr(int* num1, int* num2) {
	int* result = new int[MAX_WORD_BINARY_SIZE];
	for (int i = 0; i < MAX_WORD_BINARY_SIZE; i++)
		result[i] = num1[i] ^ num2[i];
	return result;
}

int* rotR(int* bitSet, int repeat) {
	int* result = new int[MAX_WORD_BINARY_SIZE] { 0 };
	for (int i = 0; i < MAX_WORD_BINARY_SIZE; i++)
		result[i] = bitSet[i];

	for (int i = 0; i < repeat; i++)
	{
		int temp = result[MAX_WORD_BINARY_SIZE - 1];
		for (int j = MAX_WORD_BINARY_SIZE - 1; j > 0; j--)
			result[j] = result[j - 1];
		result[0] = temp;
	}
	return result;
}

int* shR(int* bitSet, int repeat) {
	int* result = new int[MAX_WORD_BINARY_SIZE] { 0 };
	for (int i = 0; i < MAX_WORD_BINARY_SIZE; i++)
		result[i] = bitSet[i];

	for (int i = 0; i < repeat; i++)
	{
		for (int j = MAX_WORD_BINARY_SIZE - 1; j > 0; j--)
			result[j] = result[j - 1];
		result[0] = 0;
	}
	return result;
}

int* bAnd(int* num1, int* num2) {
	int* result = new int[32];

	for (int i = 0; i < 32; i++)
		result[i] = num1[i] & num2[i];

	return result;
}

int* bNot(int* bitSet) {
	int* result = new int[32];

	for (int i = 0; i < 32; i++)
		result[i] = bitSet[i] == 1 ? 0 : 1;

	return result;
}

int truthTable(int left, int right, int& carry) {
	int res = 0;
	if (!left && !right) {
		res = left ^ right ^ carry;
		carry = 0;
	}
	else if (!left || !right) {
		if (!carry) {
			carry = 0;
			res = 1;
		}
		else {
			carry = 1;
			res = 0;
		}
	}
	else if (left && right) {
		if (!carry) {
			carry = 1;
			res = 0;
		}
		else {
			carry = 1;
			res = 1;
		}
	}

	return res;
}

int* sum(int* num1, int* num2, int* num3, int* num4, int* num5) {
	return sum(sum(num1, num2, num3, num4), num5);
}

int* sum(int* num1, int* num2, int* num3, int* num4) {
	return sum(sum(num1, num2, num3), num4);
}

int* sum(int* num1, int* num2, int* num3) {
	return sum(sum(num1, num2), num3);
}

int* sum(int* num1, int* num2) {
	int* result = new int[MAX_WORD_BINARY_SIZE] { 0 };
	int carry = 0;

	for (int i = MAX_WORD_BINARY_SIZE - 1; i >= 0; i--)
		result[i] = truthTable(num1[i], num2[i], carry);

	return result;
}
