#pragma once

const char* LOGO =
"+----------------------------------------------+\n"
"|  \x1B[38;5;4m ####  \x1B[38;5;10m#   #  \x1B[38;5;1m ###     \x1B[38;5;4m####   \x1B[38;5;10m####   \x1B[38;5;1m ###  \x1B[38;5;15m |\n"
"|  \x1B[38;5;4m#      \x1B[38;5;10m#   #  \x1B[38;5;1m#   #    \x1B[38;5;4m    #  \x1B[38;5;10m#      \x1B[38;5;1m#     \x1B[38;5;15m |\n"
"|  \x1B[38;5;4m ###   \x1B[38;5;10m#####  \x1B[38;5;1m#####    \x1B[38;5;4m ###   \x1B[38;5;10m####   \x1B[38;5;1m####  \x1B[38;5;15m |\n"
"|  \x1B[38;5;4m    #  \x1B[38;5;10m#   #  \x1B[38;5;1m#   #    \x1B[38;5;4m#      \x1B[38;5;10m    #  \x1B[38;5;1m#   # \x1B[38;5;15m |\n"
"|  \x1B[38;5;4m####   \x1B[38;5;10m#   #  \x1B[38;5;1m#   #    \x1B[38;5;4m#####  \x1B[38;5;10m####   \x1B[38;5;1m ###  \x1B[38;5;15m |\n"
"|                                              |\n"
"|         Kristian Dimitrov 8MI0600166         |\n"
"+ ---------------------------------------------+\n";

const char* MAIN_MENU =
" Welcome to SHA-256 Text Manager!\n"
" Choose one of the options below:\n"
" ================================\n"
" 1. Hash message\n"
" 2. Dehash message\n"
" 3. Settings\n"
" 4. Exit\n";

const char* SETTINGS_MENU =
R"( SETTINGS
 ========
 1. Change text color
 2. Change background color
 3. Change text size
 4. Back)";

const char* HASH_MENU =
R"( HASH
 ====
 1. Input message in the console
 2. Read message from file
 3. Back)";

const char* ENTER_OPTION = "Enter option number: ";