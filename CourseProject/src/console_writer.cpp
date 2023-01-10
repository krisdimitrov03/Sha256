#include <iostream>
#include "../include/console_writer.h"
#include "../include/helper/menu_constants.h"

void print(const char message[]) {
	std::cout << message;
}

void printl(const char message[]) {
	std::cout << message << std::endl;
}

void printMainMenu() {
	printl(LOGO);
	printl(MAIN_MENU);
}

void printSettingsMenu() {
	printl(SETTINGS_MENU);
}

void printErrorMessage(const char message[]) {
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