#include <iostream>
#include <fstream>
#include "../include/helper/size_constants.h"
#include "../include/console_operator.h"
#include "../include/string_operator.h"
#include "../include/file_manager.h"

const char* file::read(const char* filename, bool& nameExists) {
	std::ifstream file(filename);

	if (file.is_open()) {
		char* result = new char[MAX_MESSAGE_LENGTH + 2]{ '\0' };
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