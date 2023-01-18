#include <iostream>
#include <conio.h>
#include "../include/console_writer.h"
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
	(void)_getch();
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