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
* <components of the app, which are printed on the console>
*
*/

#pragma once

const char* LOGO =
R"(+----------------------------------------------+
|   ####  #   #   ###     ####   ####    ###   |
|  #      #   #  #   #        #  #      #      |
|   ###   #####  #####     ###   ####   ####   |
|      #  #   #  #   #    #          #  #   #  |
|  ####   #   #  #   #    #####  ####    ###   |
|                                              |
|         Kristian Dimitrov 8MI0600166         |
+----------------------------------------------+)";

const char* MAIN_MENU =
R"( Welcome to SHA-256 Text Manager!
 Choose one of the options below:
 ================================
 1. Hash message
 2. Dehash message
 3. Change theme
 4. Exit)";

const char* SETTINGS_MENU =
R"( Theme Settings
 ==============
 1. Dark Theme
 2. Light Theme
 3. Colorized Theme
 4. Back)";

const char* HASH_MENU =
R"( HASH
 ====
 1. Input message in the console
 2. Read message from file
 3. Back)";

const char* ENTER_OPTION = "Enter option number: ";