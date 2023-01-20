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
* <app run function and its helpers for case handling>
*
*/

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
void runDehashChoice();
void runSettingsChoice(int choice);
void runExitChoice(bool& exit);
void runErrorCase();

void app::run() {
	int choice;
	char theme = 'D';
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
			runDehashChoice();
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
		console::print(PRESS_KEY_MESSAGE);
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
			console::print(PRESS_KEY_MESSAGE);
			console::readkey();
			return;
		}

		message = (char*)fileResult;
		break;
	}

	if (!(security::validateMessageLength(message))) {
		console::printErrorMessage("Message must be between 1 and 1000 characters!");
		console::print(PRESS_KEY_MESSAGE);
		console::readkey();
		return;
	}
	int i = 0;
	while (message[i] != '\0')
	{
		if (!(security::validateChar(message[i++]))) {
			console::printErrorMessage("Invalid characters detected! Try again.");
			console::print(PRESS_KEY_MESSAGE);
			console::readkey();
			return;
		}
	}

	const char* result = sha256::hash(message);
	file::writel(string::concat(message, " : ", result), "writable.txt");
	console::printl("Your hashed message:");
	console::printl("");
	console::printMessage(result);
	console::printl("");
	console::printl(SAVED_MESSAGE);
	console::printl("");
	console::printl(PRESS_KEY_MESSAGE);
	std::cin.ignore();
	console::readkey();
}

void runDehashChoice() {
	console::clear();
	char* hash = new char[MAX_CHUNK_SIZE + 1] { '\0' };
	console::print("Enter your hash: ");
	console::read(hash);
	if (hash[MAX_CHUNK_SIZE - 1] == '\0') {
		console::printErrorMessage("Input is not in the correct format!");
		console::print(PRESS_KEY_MESSAGE);
		console::readkey();
		return;
	}

	bool success = true;
	const char* result = sha256::dehash(hash, success);

	if (!success) {
		console::printErrorMessage("Sha256 Manager was not able to read your message.");
		console::print(PRESS_KEY_MESSAGE);
		console::readkey();
		return;
	}

	console::printl("Your message:\n");
	console::printMessage(result);
	console::printl("");
	console::print(PRESS_KEY_MESSAGE);
	console::readkey();
}

void runSettingsChoice(int choice) {
	console::clear();
	console::printSettingsMenu();
	std::cin >> choice;

	switch (choice) {
	case 1:
		color::changeTheme('D');
		break;
	case 2:
		color::changeTheme('L');
		break;
	case 3:
		color::changeTheme('C');
		break;
	case 4:
		break;
	default:
		runErrorCase();
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
	console::clear();
	console::printErrorMessage(WRONG_INPUT_MESSAGE);
	console::printl("");
	console::print(PRESS_KEY_MESSAGE);
	console::readkey();
}