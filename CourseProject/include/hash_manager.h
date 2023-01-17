#pragma once

/**
*   \brief Gets message and its length and returns the hash as a string.
*   \param message - the text to be hashed
*   \param length - the length of the message
*   \return string - hashed message
**/
const char* hash(const char* message);

/**
*   \brief Gets hashed message and its length and returns the dehashed message as a string.
*   \param hashedMessage - the hash to be operated with
*   \param length - the length of the hashedMessage
*   \return string - dehashed message
**/
const char* dehash(const char* hashedMessage, int length);