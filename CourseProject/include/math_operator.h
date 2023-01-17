#pragma once
#include "./helper/size_constants.h"

bool isPrime(int number);

int* getFirstNPrimes(int count);

long long getConstantInDecimal(int num, const char* rootType);

char* hex(int* binary);

int* binary(long long number, int padSize = DEFAULT_VALUE);

int decimal(int* number, int length);

int binaryLen(long long number);

///bitwise operations

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