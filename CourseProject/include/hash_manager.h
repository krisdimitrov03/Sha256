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
* <declaration of hash and dehash functions in hash_manager.cpp>
*
*/

#pragma once

namespace sha256 {
	/**
	*   @param message - the text to be hashed
	*   @return string - hashed message
	**/
	const char* hash(const char* message);

	/**
	*   @param hashedMessage - char*
	*   @return char* - result if message can be dehashed
	**/
	const char* dehash(const char* hashedMessage, bool& success);
}