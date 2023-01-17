#include <iostream>
#include <conio.h>
#include "../include/console_writer.h"
#include "../include/file_manager.h"
#include "../include/hash_manager.h"
#include "../include/helper/message_constants.h"
#include "../include/helper/size_constants.h"
#include "../include/app.h"

void runChoice(int choice, bool& exit);

void app::run() {
	int choice;
	while (true)
	{
		system("cls");
		console::printMainMenu();
		std::cin >> choice;

		bool exit = false;
		runChoice(choice, exit);

		if (exit)
			return;
	}
}

void runChoice(int choice, bool& exit) {
	//hash
	if (choice == 1) {
		//printl(hash(TEST_INPUT));
		//printl(hash("hello world"));
		//system("cls");
		console::printl("Make sure the text in your file is no longer than 500 characters.");
		console::print("Enter file name: ");
		char* filename = new char[MAX_MESSAGE_LENGTH + 2]{ '0' };
		std::cin >> filename;
		bool nameExists = false;
		const char* message = file::read(filename, nameExists);

		if (!nameExists) {
			console::print(" Press any key to continue...");
			(void)_getch();
			return;
		}

		const char* result = sha256::hash(TEST_INPUT);
		console::print("Your hashed message: ");
		console::printl(result);
		console::printl("Press any key to continue...");
		(void)_getch();
	}
	//dehash
	else if (choice == 2) {

	}
	//settings
	else if (choice == 3) {
		system("cls");
		choice = 0;
		console::printSettingsMenu();
		std::cin >> choice;
		//cases of settings
	}
	//exit
	else if (choice == 4) {
		exit = true;
		system("cls");
		console::printl("Bye, bye, User! :(");
		return;
	}
	//error
	else {
		system("cls");
		console::printErrorMessage(WRONG_INPUT_MESSAGE);
		console::printl("\n");
		_getch();
	}
}