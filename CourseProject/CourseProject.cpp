#include <iostream>
#include "ConsoleWriter.h"
#include "FileManager.h"
#include "HashManager.h"
#include "Constants.h"

void run(int choice, bool &exit);

int main()
{
	while (true)
	{
		printMainMenu();
		int choice;
		std::cin >> choice;

		bool exit = false;
		run(choice, exit);
		if (exit)
			return 0;
	}
}

void run(int choice, bool& exit) {
	//hash
	if (choice == 1) {
		hash("hello world", 11);
	}
	//dehash
	else if (choice == 2) {

	}
	//settings
	else if (choice == 3) {
		choice = 0;
		printSettingsMenu();
		std::cin >> choice;
		//cases of settings
	}
	//exit
	else if (choice == 4) {
		exit = true;
		return;
	}
	else {
		printErrorMessage(WrongInputMessage);
		printl("\n");
	}
}