#include <iostream>
#include <conio.h>
#include "./include/console_writer.h"
#include "./include/file_manager.h"
#include "./include/hash_manager.h"
#include "./include/helper/message_constants.h"

void run(int choice, bool& exit);

int main()
{
	int choice;
	while (true)
	{
		system("cls");
		printMainMenu();
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
		/*system("cls");
		print("Enter file name: ");
		char* filename = new char{ '0' };
		std::cin >> filename;
		bool nameExists = false;
		const char* message = read(filename, nameExists);

		if (!nameExists) {
			_getch();
			return;
		}

		const char* result = hash(message, 11);
		print("Your hashed message: ");
		printl(result);
		printl("Press any key to continue...");
		_getch();*/
	}
	//dehash
	else if (choice == 2) {

	}
	//settings
	else if (choice == 3) {
		system("cls");
		choice = 0;
		printSettingsMenu();
		std::cin >> choice;
		//cases of settings
	}
	//exit
	else if (choice == 4) {
		exit = true;
		system("cls");
		printl("Bye, bye, User! :(");
		return;
	}
	else {
		system("cls");
		printErrorMessage(WRONG_INPUT_MESSAGE);
		printl("\n");
		_getch();
	}
}