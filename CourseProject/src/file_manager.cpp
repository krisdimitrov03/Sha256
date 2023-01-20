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
* <functions for working with files>
*
*/

#include <iostream>
#include <fstream>
#include "../include/helper/size_constants.h"
#include "../include/console_operator.h"
#include "../include/string_operator.h"
#include "../include/file_manager.h"

const char* file::read(const char* filename, bool& nameExists) {
	std::ifstream file(filename);

	if (file.is_open()) {
		char* result = new char[MAX_MESSAGE_LENGTH + 2] { '\0' };
		file.read(result, MAX_MESSAGE_LENGTH + 2);
		nameExists = true;
		file.close();
		return result;
	}
	else {
		console::printErrorMessage("Cannot open this file. Try again with another name.");
		return "failed";
	}
}

char** file::readAllLines(const char* filename, int& length) {
	std::ifstream file(filename);

	if (file.is_open()) {
		int initLength = MAX_MESSAGE_LENGTH + MAX_CHUNK_SIZE + 4;
		int i = 0;
		char** result = new char* [initLength];
		char* line = new char [initLength] {'\0'};
		file.getline(line, initLength);
		while (line[0] != '\0') {
			result[i] = new char[initLength] {'\0'};
			for (int j = 0; line[j] != '\0'; j++)
				result[i][j] = line[j];
			length++;
			file.getline(line, initLength);
		}
		return result;
	}
	else {
		return new char* [5];
	}
}

void file::write(const char* text, const char* filename) {
	std::ofstream file(filename, std::ios::app);

	if (file.is_open()) {
		int length = 0;
		while (text[length++] != '\0');
		length--;
		file.write(text, length);
		file.close();
	}
	else {
		console::printErrorMessage("Cannot open this file. Try again with another name.");
	}
}

void file::writel(const char* text, const char* filename) {
	write(string::concat(text, "\n"), filename);
}