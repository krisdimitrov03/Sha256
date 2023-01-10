#include <iostream>
#include <fstream>
#include "../include/console_writer.h"
#include "../include/file_manager.h"

const char* read(const char* filename, bool& nameExists) {
	std::ifstream file(filename);

	if (file.is_open()) {
		//char result[1024];
		//int i = 0;
		//char current = file.get();
		//while (current != '\0') {
		//	result[i++] = current;
		//	current = file.get();
		//}
		//return result;
	}
	else {
		printErrorMessage("Cannot open this file. Try again with another name.");
		return "failed";
	}
}

void write(const char* text, const char* filename) {

}