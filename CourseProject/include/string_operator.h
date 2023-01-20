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
* <declaration of functions in string_operator.cpp>
*
*/

#pragma once

namespace string {
	/**
	*   @param leftStr - char*, left value
	*   @param rightStr - char*, right value
	*   @return char* - the result of concatenating the two strings
	**/
	const char* concat(const char* leftStr, const char* rightStr);

	/**
	*   @param leftStr - char*, left value
	*   @param midStr - char*, mid value
	*   @param rightStr - char*, right value
	*   @return char* - the result of concatenating the three strings
	**/
	const char* concat(const char* leftStr, const char* midStr, const char* rightStr);

	/**
	*   @param str - char*, full string
	*	@param length - int, the lenght of str
	*   @return char* - substring, representing only the hashValue
	**/
	const char* getHashSubstring(const char* str, int length);

	const char* getMessageSubstring(const char* str);
}