#include <iostream>
#include "ConsoleWriter.h"
#include "FileManager.h"
#include "HashManager.h"
#include "Constants.h"

void run(int choice);

int main()
{
	while (true)
	{
		writeMainMenu();
		int choice;
		std::cin >> choice;
		run(choice);
	}
}

void run(int choice) {
	if (choice == 1) {

	}
	else if (choice == 2) {

	}
	else if (choice == 3) {

	}
	else {
		std::cout << WrongInputMessage << std::endl;
	}
}