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
* <function for changing color theme of the app>
*
*/

#include <iostream>
#include "../include/decoration_manager.h"
#include "../include/helper/theme_constants.h"
#include "../include/string_operator.h"

void color::changeTheme(const char theme) {
	const char* themeValues = new char[3] {'\0'};
	switch (theme) {
	case 'D':
		themeValues = DARK_THEME;
		break;
	case 'L':
		themeValues = LIGHT_THEME;
		break;
	case 'C':
		themeValues = COLORIZED_THEME;
		break;
	}

	system(string::concat("color ", themeValues));
}