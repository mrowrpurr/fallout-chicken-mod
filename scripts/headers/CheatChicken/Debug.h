#pragma once

#define debug(text) debug_msg("[CheatChicken] " + text + "\n")
#define debug1(text, a1) debug_msg("[CheatChicken] " + sprintf(text, a1) + "\n")
#define debug2(text, a1, a2) debug_msg("[CheatChicken] " + sprintf_array(text, [a1, a2]) + "\n")
#define debug3(text, a1, a2, a3) debug_msg("[CheatChicken] " + sprintf_array(text, [a1, a2, a3]) + "\n")
#define debug4(text, a1, a2, a3, a4) debug_msg("[CheatChicken] " + sprintf_array(text, [a1, a2, a3, a4]) + "\n")
#define debug5(text, a1, a2, a3, a4, a5) debug_msg("[CheatChicken] " + sprintf_array(text, [a1, a2, a3, a4, a5]) + "\n")
#define debug6(text, a1, a2, a3, a4, a5, a6) debug_msg("[CheatChicken] " + sprintf_array(text, [a1, a2, a3, a4, a5, a6]) + "\n")
