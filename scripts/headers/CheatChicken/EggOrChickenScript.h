/*
    Used to add functionality for Eggs and Chickens
    to hijacked scripts for The Cheat Chicken *bukaw!*
*/

#include "define.h"
#include "command.h"
#include "sfall/sfall.h"
#include "sfall/lib.arrays.h"
#include "sfall/lib.strings.h"
#include "CheatChicken.h"
#include "CheatChicken/Messages.h"
#include "FormattedDebug.h"
#include "FormattedDisplay.h"

import variable cheatchicken_config;
import variable cheatchicken_data;

variable config;
variable data;

procedure start begin
    config = cheatchicken_config;
    data   = cheatchicken_data;
end

procedure critter_p_proc begin
    if self_obj == data.chicken_obj then
        animate_move_to_tile(Future_Distance_From_Dude(2));
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
            // Found the replacement character - TODO check to see we're not on its home map(s)
            variable character_info = config_section;

            // Replace the .frm(s) of the character with our configured .frm(s) for this egg's chicken
            variable chicken_name = config.Egg.hatches;
            variable chicken_info = config["Chicken:" + chicken_name];
            variable chicken_idle_path = chicken_info.idle_animation;
            variable character_idle_path = sprintf("art\\critters\\%s", character_info.idle_animation);

            variable file = fs_copy("MOVE.FRM", character_idle_path);
            // variable file = fs_copy(character_idle_path, "MOVE.FRM");
            // variable file = fs_copy(character_idle_path, character_idle_path);
            display2("character, chicken", character_idle_path, chicken_idle_path);

            data.chicken_obj = create_object_sid(atoi(character_info.pid), 0, 0, atoi(character_info.script_id));

            critter_attempt_placement(data.chicken_obj, dude_tile, dude_elevation);

            party_add(data.chicken_obj);

            break;
        end
    end
end

procedure drop_p_proc begin
    script_overrides;
    call spawn_chicken;
end



