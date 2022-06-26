#ifndef CHEATCHICKEN_CONFIGURATION_H
#define CHEATCHICKEN_CONFIGURATION_H

#include "..\headers\sfall\sfall.h"

// TODO - store config sections in "permanent" arrays and don't touch the file system for each call.
//        for now, this is actually convenient for testing!

#define config_filename "data\\CheatChicken.ini"
#define get_keyboard_shortcut_config get_ini_section(config_filename, "KeyboardShortcut")

#endif