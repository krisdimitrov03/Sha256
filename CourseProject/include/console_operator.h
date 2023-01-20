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
* <declaration of functions in console_operator.cpp>
*
*/

#pragma once

namespace console {
	void printMainMenu();

	void printErrorMessage(const char* message);

	void printMessage(const char* message);

	void printSettingsMenu();

	void printHashMenu();

	void print(const char* message);

	void printl(const char* message);

	void clear();

	void readkey();

	void read(char* dest);

	void read(int& value);

	void readLine(char* dest, int length);
}