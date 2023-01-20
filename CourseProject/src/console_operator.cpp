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
* <functions for console managing>
*
*/

#include <iostream>
#include "../include/console_operator.h"
#include "../include/helper/components.h"

void console::print(const char* message) {
	std::cout << message;
}

void console::printl(const char* message) {
	std::cout << message << std::endl;
}

void console::clear() {
	system("cls");
}

void console::readkey() {
	std::cin.get();
	std::cin.ignore();
}

void console::printMainMenu() {
	printl(LOGO);
	printl(MAIN_MENU);
	print(ENTER_OPTION);
}

void console::printSettingsMenu() {
	printl(SETTINGS_MENU);
	print(ENTER_OPTION);
}

void console::printHashMenu() {
	printl(HASH_MENU);
	print(ENTER_OPTION);
}

void console::printErrorMessage(const char* message) {
	print("---");
	int i = 0;
	while (message[i++] != '\0')
		print("-");
	printl("---");

	print("|| ");
	print(message);
	printl(" ||");

	print("---");
	i = 0;
	while (message[i++] != '\0')
		print("-");
	printl("---");
}

void console::printMessage(const char* message) {
	print("**");
	int i = 0;
	while (message[i++] != '\0')
		print("*");
	printl("**");

	print("* ");
	print(message);
	printl(" *");

	print("**");
	i = 0;
	while (message[i++] != '\0')
		print("*");
	printl("**");
}

void console::read(char* dest) {
	std::cin.ignore();
	std::cin >> dest;
}

void console::read(int& value) {
	std::cin.ignore();
	std::cin >> value;
}

void console::readLine(char* dest, int length) {
	std::cin.ignore();
	std::cin.getline(dest, length);
}