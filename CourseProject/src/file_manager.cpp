#include <iostream>
#include <fstream>
#include "../include/console_writer.h"
#include "../include/file_manager.h"

const char* file::read(const char* filename, bool& nameExists) {
	std::ifstream file(filename);

	if (file.is_open()) {
		char* result = new char[502] {'\0'};
		nameExists = true;
		int i = 0;
		/*char current = file.getline(result, 501);
		while (current != '\0') {
			result[i++] = current;
			current = file.get();
		}*/
		return result;
	}
	else {
		console::printErrorMessage("Cannot open this file. Try again with another name.");
		return "failed";
	}
}

void file::write(const char* text, const char* filename) {

}