/*
    Used to add functionality for Eggs and Chickens
    to hijacked scripts for The Cheat Chicken *bukaw!*
*/

#include "define.h"
#include "command.h"
#include "CheatChicken.h"

procedure drop_p_proc begin
    display_msg("YOU DROPPED THE EGG");
    script_overrides;
end
