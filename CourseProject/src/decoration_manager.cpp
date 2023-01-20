#include <iostream>
#include "../include/decoration_manager.h"
#include "../include/helper/color_constants.h"
#include "../include/string_operator.h"

void color::changeForeColor(const char color) {
	const char* command = string::concat("\x1b[38;5;", new char[2]{ color }, "m");
	std::cout << command;
}

void color::changeBackColor(const char color) {
	const char* command = string::concat("\x1b[48;5;", new char[2]{ color }, "m");
	std::cout << command;
}