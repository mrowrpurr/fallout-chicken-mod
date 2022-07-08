/*
    Used to add functionality for Eggs and Chickens
    to hijacked scripts for The Cheat Chicken *bukaw!*
*/

#include "define.h"
#include "command.h"
#include "CheatChicken.h"

import variable cheatchicken_config_exported;
import variable cheatchicken_data_exported;

#define MSG_EGG_NAME 101
#define MSG_YOU_SEE  102

procedure look_at_p_proc begin
    variable map = cheatchicken_config_exported;
    script_overrides;
    display_msg("import DATA: " + cheatchicken_data_exported);
    display_msg("import CONFIG: " + cheatchicken_config_exported);
    display_msg("SCRIPT_ID: " + map.Egg.script_id);
    // variable script_id = get_script(self_obj);
    display_msg(
        message_str(map.Egg.script_id, MSG_YOU_SEE) +  message_str(map.Egg.script_id, MSG_EGG_NAME)
    );
end

procedure drop_p_proc begin
    script_overrides;
    display_msg("YOU DROPPED THE EGG");
end
