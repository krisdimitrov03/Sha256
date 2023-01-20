#include <iostream>
#include "../include/console_operator.h"
#include "../include/file_manager.h"
#include "../include/hash_manager.h"
#include "../include/string_operator.h"
#include "../include/helper/message_constants.h"
#include "../include/helper/size_constants.h"
#include "../include/helper/color_constants.h"
#include "../include/validator.h"
#include "../include/decoration_manager.h"
#include "../include/app.h"

void runHashChoice(int choice);
void runDehashChoice(int choice);
void runSettingsChoice(int choice);
void runExitChoice(bool& exit);
void runErrorCase();

void app::run() {
	int choice;
	while (true)
	{
		console::clear();
		console::printMainMenu();
		std::cin >> choice;
		bool exit = false;

		switch (choice) {
		case 1:
			runHashChoice(choice);
			break;
		case 2:
			runDehashChoice(choice);
			break;
		case 3:
			runSettingsChoice(choice);
			break;
		case 4:
			runExitChoice(exit);
			break;
		default:
			runErrorCase();
			break;
		}

		if (exit)
			return;
	}
}

void runHashChoice(int choice) {
	console::clear();
	console::printHashMenu();
	console::read(choice);

	if (choice == 3)
		return;
	if (choice != 1 && choice != 2) {
		console::printErrorMessage(WRONG_INPUT_MESSAGE);
		console::print(PRESS_KEY);
		console::readkey();
		return;
	}

	char* message = new char[MAX_MESSAGE_LENGTH + 2] { '\0' };
	console::clear();

	switch (choice) {
	case 1:
		console::printl("Enter message(No longer than 1000 characters):");
		console::readLine(message, MAX_MESSAGE_LENGTH + 2);
		break;
	case 2:
		char* filename = new char[102];
		bool nameExists = false;
		console::print("Enter file name: ");
		std::cin >> filename;
		const char* fileResult = file::read(filename, nameExists);

		console::printl("");

		if (!nameExists) {
			console::print(PRESS_KEY);
			console::readkey();
			return;
		}

		message = (char*)fileResult;
		break;
	}

	if (!(security::validateMessageLength(message))) {
		console::printErrorMessage("Message must be between 1 and 1000 characters!");
		console::print(PRESS_KEY);
		console::readkey();
		return;
	}

	const char* result = sha256::hash(message);
	file::write(string::concat(message, " : ", result), "writable.txt");
	console::printl("Your hashed message:");
	console::printl("");
	console::printMessage(result);
	console::printl("");
	console::printl(PRESS_KEY);
	console::readkey();
}

void runDehashChoice(int choice) {

}

void runSettingsChoice(int choice) {
	console::clear();
	console::printSettingsMenu();
	std::cin >> choice;

	switch (choice) {
	case 1:
		//console::printColorsMenu();
		color::changeForeColor(BLUE);
		break;
	case 2:
		color::changeBackColor(RED);
		break;
	}
}

void runExitChoice(bool& exit) {
	exit = true;
	console::clear();
	console::printMessage("Goodbye! See you soon!");
	return;
}

void runErrorCase() {
	system("cls");
	console::printErrorMessage(WRONG_INPUT_MESSAGE);
	console::printl("");
	console::print(PRESS_KEY);
	console::readkey();
}