#include <iostream>
#include "../include/decoration_manager.h"
#include "../include/helper/color_constants.h"
#include "../include/string_operator.h"

void color::changeForeColor(const char color) {
	const char* command = string::concat("Color ", new char[2] { color });
	system(command);
}

void color::changeBackColor(const char color) {
	const char* command = string::concat("Color ", new char[3] { color, '0' });
	system(command);
}