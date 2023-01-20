#pragma once

namespace sha256 {
	/**
	*   @brief Gets message and its length and returns the hash as a string.
	*   @param message - the text to be hashed
	*   @return string - hashed message
	**/
	const char* hash(const char* message);
}