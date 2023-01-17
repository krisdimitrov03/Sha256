#include <iostream>
#include <conio.h>
#include "../include/console_writer.h"
#include "../include/file_manager.h"
#include "../include/hash_manager.h"
#include "../include/helper/message_constants.h"
#include "../include/helper/size_constants.h"
#include "../include/app.h"

void runHashChoice(int choice, bool& exit);
void runDehashChoice(int choice, bool& exit);
void runSettingsChoice(int choice, bool& exit);
void runExitChoice(int choice, bool& exit);
void runErrorCase();

void app::run() {
	int choice;
	while (true)
	{
		system("cls");
		console::printMainMenu();
		std::cin >> choice;
		bool exit = false;

		switch (choice) {
		case 1:
			runHashChoice(choice, exit);
			break;
		case 2:
			runDehashChoice(choice, exit);
			break;
		case 3:
			runSettingsChoice(choice, exit);
			break;
		case 4:
			runExitChoice(choice, exit);
			break;
		default:
			runErrorCase();
			break;
		}

		if (exit)
			return;
	}
}

void runHashChoice(int choice, bool& exit) {
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

void runDehashChoice(int choice, bool& exit) {

}

void runSettingsChoice(int choice, bool& exit) {
	system("cls");
	choice = 0;
	console::printSettingsMenu();
	std::cin >> choice;
	//cases of settings
}

void runExitChoice(int choice, bool& exit) {
	exit = true;
	system("cls");
	console::printl("Bye, bye, User! :(");
	return;
}

void runErrorCase() {
	system("cls");
	console::printErrorMessage(WRONG_INPUT_MESSAGE);
	console::printl("\n");
	(void)_getch();
}