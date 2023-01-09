#include <iostream>
#include "ConsoleWriter.h"

void print(const char message[]) {
	std::cout << message;
}

void printl(const char message[]) {
	std::cout << message << std::endl;
}

void printLogo() {
	printl("+----------------------------------------------+");
	printl("|   ####  #   #   ###     ####   ####    ###   |");
	printl("|  #      #   #  #   #        #  #      #      |");
	printl("|   ###   #####  #####     ###   ####   ####   |");
	printl("|      #  #   #  #   #    #          #  #   #  |");
	printl("|  ####   #   #  #   #    #####  ####    ###   |");
	printl("|                                              |");
	printl("|         Kristian Dimitrov 8MI0600166         |");
	printl("+----------------------------------------------+");
}

void printMainMenu() {
	printLogo();
	printl("Welcome to SHA-256 Text Manager!");
	printl("Choose one of the options below:");
	printl("================================");
	printl("1. Hash message");
	printl("2. Dehash message");
	printl("3. Settings");
	printl("4. Exit");
	print("Enter option number: ");
}

void printSettingsMenu() {
	printl("SETTINGS");
	printl("========");
	printl("1. Change text color");
	printl("2. Change background color");
	printl("3. Change text size");
	printl("4. Back");
	print("Enter option number: ");
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