/*
    Used to add functionality for Eggs and Chickens
    to hijacked scripts for The Cheat Chicken *bukaw!*
*/

#include "define.h"
#include "command.h"
#include "sfall/lib.arrays.h"
#include "sfall/lib.strings.h"
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
    display_msg("LOOK AT...");
    display_msg(get_msg(MSG_YOU_SEE) + get_msg(MSG_EGG_NAME));
end

procedure spawn_chicken begin
    variable config_section_name, config_section;
    foreach config_section_name: config_section in config begin
        if string_starts_with(config_section_name, "ReplacementCharacter:") then begin
            debug_array(config_section);
            display_msg("SPAWN " + atoi(config_section.pid) + " with script " + atoi(config_section.script_id));
            data.chicken_obj = create_object_sid(atoi(config_section.pid), 0, 0, atoi(config_section.script_id));
            critter_attempt_placement(data.chicken_obj, dude_tile, dude_elevation);
            break;
        end
    end
end

procedure drop_p_proc begin
    script_overrides;
    call spawn_chicken;
end



