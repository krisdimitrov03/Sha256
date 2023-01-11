#pragma once
#include "./helper/size_constants.h"

bool isPrime(int number);

long long getConstantInDecimal(int num, const char* rootType);

int binaryLen(long long number);

int* binary(long long number, int padSize = -1);

int* xOr(int* num1, int* num2, int* num3);

int* rotR(int* bitSet, int repeat);

int* shR(int* bitSet, int repeat);

int* sum(int* num1, int* num2, int* num3, int* num4);