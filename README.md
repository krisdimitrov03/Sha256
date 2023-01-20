# Course Project # 6 - SHA256 - Documentation
> **Kristian Dimitrov** - 8MI0600166
### Helpful links

[Hashing algorithm representation](https://sha256algorithm.com/)

## What is Sha-256 Manager?
This is an application for hashing text message by `SHA-256` algorithm (part of `Security Hashing Algorithm 2`). It is written on C++.

## Structure
- ### Header files
  All header files are in `include` folder. They consist of function declarations and global constants. Here are the files:
- ### Source files
  All source files are in `src` folder. Each of them include implementation of functions in the relevant header file and helper functions  if necessary.
- ### Text files
  They are the place where messages can be read from - `readable.txt` and where hashes are written - `writable.txt`.

## Functionalities
- ### Hashing message
  Message hashing algorithm is being implemented in the `hash()` function in `hashing_manager.cpp`. This function gets the message as a parameter and returns the SHA256 hash as a const char pointer. Here is an example:
  
  Input:
  ```
  hello world
  ```
  Output:
  ```
  b94d27b9934d3e08a52e52d7da7dabfac484efe37a5380ee9088f7ace2efcde9
  ```
  There are several main stages inside the hashing algorithm and they are realized by helper functions:
  - Pre-processing input - `preProcessInput()`
  - Splitting into words of 32 bit - `splitInput()`
  - Getting the chunk by specific formulas - `getChunk()`
  - Generating the `h` constants - `generateAtoHConstants()`
  - Generating the `k` constants - `generateKConstants()`
  - Modifying new `h` constants by specific formulas - `modifyAtoHConstants()`
  - Bitwise addition of old and new `h` constants - `sumOldAndNewConstants()`
  - Turning the result into hexadecimal - `getHash()`

- ### Reading message from hash
  The user should type hash in the console and this hash is being searched in the `writable.txt` file and if it's found - the app returns the dehashed message. Here is an example:
  #### Input:
  ```
  b94d27b9934d3e08a52e52d7da7dabfac484efe37a5380ee9088f7ace2efcde9
  ```
  #### Output:
  ```
  hello world
  ```
- ### Reading from console
  This functionality is realised in the `read()` function overloads for `char*` and `int` placed in `console_operator.cpp`. It is used to read a message from the console, no matter if there are spaces in it.
- ### Reading from file
  This functionality is implemented by `ifstream`, part of `<fstream>` library. The user is asked to type file name in the console and the message is being read from the file with this name. The default file for this is `readable.txt`. The method for this operation is `read()` placed in `file_manager.cpp`.
- ### Writing in file
  Writing text in file is realised in the `write()` and `writel()` methods in `file_manager.cpp`. It gets message to be written and file name and places the text in the file with the same name. The default file for this is `writable.txt`. For this functionality is used `ofstream`, part of `<fstream>` library. Data is being written in the file in the following format:
  ```
  <message> : <hashed-message>
  ```
- ### Changing app theme
  This is the bonus part of the entire project. The user can choose from three color themes to change the appearence of the application:
  - **Dark**
  - **Light**
  - **Colorized**
- ### Validations
  #### There are two main constraints which the input should handle:
  - **Char constraint** - all characters should be from the standart ASCII table (from 0 to 128)
  - **Length constraint** - the length of the message should be between 1 and 1000
  #### That is why, before the hashing algorithm is processed, the text message goes through two validations:
  - `validateChar()`
  - `validateMessageLength()`

**Note:** No external libraries were used for creating the application except from `<fstream>`.
