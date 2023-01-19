#pragma once

namespace console {
	void printMainMenu();

	void printErrorMessage(const char* message);

	void printMessage(const char* message);

	void printSettingsMenu();

	void printHashMenu();

	void print(const char* message);

	void printl(const char* message);

	void clear();

	void readkey();

	void read(char* dest);

	void read(int& value);

	void readLine(char* dest, int length);
}