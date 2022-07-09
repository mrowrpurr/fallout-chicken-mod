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
    display_msg(get_msg(MSG_YOU_SEE) + get_msg(MSG_EGG_NAME));
end

procedure spawn_chicken begin
    variable config_section_name, config_section;
    foreach config_section_name: config_section in config begin
        if string_starts_with(config_section_name, "ReplacementCharacter:") then begin
            // Found the replacement character - TODO check to see we're not on its home map(s)
            variable character_info = config_section;

            // Replace the .frm(s) of the character with our configured .frm(s) for this egg's chicken
            variable chicken_name          = config.Egg.hatches,
                     chicken_info          = config["Chicken:" + chicken_name],
                     chicken_idle_frm      = chicken_info.idle_animation,
                     chicken_move_frm      = chicken_info.moving_animation,
                     character_idle_frm    = sprintf("art\\critters\\%s", character_info.idle_animation),
                     character_moving_frms = string_split(character_info.moving_animations, ",");

            // Update the idle animation to be the chicken.
            // Note: although we do not use the `file` variable, it is required
            // (fs_copy won't work if you don't save the results into a variable)
            variable file = fs_copy(character_idle_frm, chicken_idle_frm);

            // Update all moving animations
            variable frm;
            foreach frm in character_moving_frms begin
                file = fs_copy(sprintf("art\\critters\\%s", frm), chicken_move_frm);
            end

            // Spawn the character
            data.chicken_obj = create_object_sid(atoi(character_info.pid), 0, 0, atoi(character_info.script_id));
            critter_attempt_placement(data.chicken_obj, dude_tile, dude_elevation);
            
            // Add them to your party (this allows them to follow you from map to map)
            party_add(data.chicken_obj);

            break;
        end
    end
end

procedure drop_p_proc begin
    script_overrides;
    call spawn_chicken;
end



