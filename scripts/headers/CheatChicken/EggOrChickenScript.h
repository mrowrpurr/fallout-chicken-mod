/*
    Used to add functionality for Eggs and Chickens
    to hijacked scripts for The Cheat Chicken *bukaw!*
*/

#include "define.h"
#include "command.h"
#include "CheatChicken.h"
#include "CheatChicken/Messages.h"
#include "FormattedDebug.h"

import variable cheatchicken_config;
import variable cheatchicken_data;

variable config;
variable data;

procedure start begin
    config = cheatchicken_config;
    data   = cheatchicken_data;
end

procedure look_at_p_proc begin
    script_overrides;
    display_msg(get_msg(MSG_YOU_SEE) + get_msg(MSG_EGG_NAME));
end

procedure drop_p_proc begin
    script_overrides;
    display_msg("YOU DROPPED THE EGG");
end
