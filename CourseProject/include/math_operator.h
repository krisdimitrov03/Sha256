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
* <declaration of functions in math_operator.cpp>
*
*/

#pragma once
#include "./helper/size_constants.h"

namespace math {
	/// math operations

	bool isPrime(int number);

	int* getFirstNPrimes(int count);

	long long getConstantInDecimal(int num, const char* rootType);

	/// convertion of numbers

	char* hex(int* binary);

	int* binary(long long number, int padSize = DEFAULT_VALUE);

	int decimal(int* number, int length);

	int binaryLen(long long number);

	/// bitwise operations - overloads for multiple parameters

	int* xOr(int* num1, int* num2, int* num3);
	int* xOr(int* num1, int* num2);

	int* rotR(int* bitSet, int repeat);

	int* shR(int* bitSet, int repeat);

	int* bAnd(int* num1, int* num2);

	int* bNot(int* bitSet);

	int truthTable(int left, int right, int& carry);

	int* sum(int* num1, int* num2, int* num3, int* num4, int* num5);
	int* sum(int* num1, int* num2, int* num3, int* num4);
	int* sum(int* num1, int* num2, int* num3);
	int* sum(int* num1, int* num2);
}