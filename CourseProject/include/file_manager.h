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
* <declaration of functions in file_manager.cpp>
*
*/

#pragma once

namespace file {
	/**
	*   @param filename - char*, name of the file
	*   @param nameExists - bool, by reference
	*   @return char* - the text in the file and sets the value of nameExists to false, if file doesn't exist
	**/
	const char* read(const char* filename, bool& nameExists);

	/**
	*	Writes the message in the file with filename
	*   @param text - char*, message
	*   @param filename - char*, name of the file
	**/
	void write(const char* text, const char* filename);

	/**
	*	Writes the message in the file with filename and goes to a new line
	*   @param text - char*, message
	*   @param filename - char*, name of the file
	**/
	void writel(const char* text, const char* filename);
}