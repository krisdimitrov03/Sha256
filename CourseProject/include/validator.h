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
* <declaration of functions in validator.cpp>
*
*/

#pragma once

namespace security {
	/**
	*   @param value - char
	*   @return bool - if char value is valid
	**/
	bool validateChar(char value);

	/**
	*   @param message - char*
	*   @return bool - if message length is valid
	**/
	bool validateMessageLength(const char* message);
}