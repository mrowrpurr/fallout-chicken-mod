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
#include "CheatChicken/Scripts.h"
#include "Fallout1in2.h"
#include "FormattedDebug.h"
#include "FormattedDisplay.h"

import variable cheatchicken_config;
import variable cheatchicken_data;

variable is_started;

variable config;
variable data;

#include "CheatChicken/DialogueActions.h"
#include "CheatChicken/Dialogue.h"

// ADD art_change_fid_num option! unlimited choices/followers. but ONE custom art allowed.

procedure map_enter_p_proc begin
    // Has to be reset on map enter - set to the name you give to the chicken
    set_scr_name("The Chicken");

    if self_obj != data.egg_obj and self_obj != data.chicken_obj then
        call original_map_enter_p_proc;
end

procedure critter_p_proc begin
    if self_obj == data.chicken_obj then
        animate_move_obj_to_tile(self_obj, Future_Distance_From_Dude(2), ANIMATE_WALK);
end

procedure look_at_p_proc begin
    if self_obj == data.egg_obj then begin
        script_overrides;
        display_msg(get_msg(MSG_YOU_SEE) + get_msg(MSG_EGG_NAME));
    end else if self_obj == data.chicken_obj then begin
        script_overrides;
        display_msg(get_msg(MSG_YOU_SEE) + data.chicken_name);
    end
end

procedure spawn_chicken begin
    if not self_obj == data.egg_obj then return;

    display_msg("SPAWN");

    variable fallout_et_tu = is_running_ettu;
    variable config_section_name, config_section;
    foreach config_section_name: config_section in config begin
        if string_starts_with(config_section_name, "ReplacementCharacter_") then begin
            
            display_msg("config_section_name: " + config_section_name);

            // Found a replacement character - TODO check to see we're not on its home map(s)
            variable character_info = config_section;

            if (not fallout_et_tu) or (fallout_et_tu and character_info.game == "ettu") then begin

                // Replace the .frm(s) of the character with our configured .frm(s) for this egg's chicken
                variable chicken_name          = config.Egg.hatches,
                         chicken_info          = config["Chicken_" + chicken_name],
                         chicken_idle_frm      = chicken_info.idle_animation,
                         chicken_move_frm      = chicken_info.moving_animation,
                         character_idle_frm    = sprintf("art\\critters\\%s", character_info.idle_animation),
                         character_pid         = atoi(character_info.pid);

                // character_moving_frms = string_split(character_info.moving_animations, ","),
                variable character_moving_frms = [];
                variable character_info_keys = array_keys(character_info);
                variable key;
                foreach key in character_info_keys begin
                    if string_starts_with(key, "moving_animations") then begin
                        // * Merge arr2 on top of the arr1 
                        call array_append(character_moving_frms, string_split(character_info[key], ","));
                    end
                end
                
                display1("chicken:", chicken_name);

                // Update the idle animation to be the chicken.
                // Note: although we do not use the `file` variable, it is required
                // (fs_copy won't work if you don't save the results into a variable)
                variable file = fs_copy(character_idle_frm, chicken_idle_frm);

                // // // // // Update all moving animations
                variable frm;
                foreach frm in character_moving_frms begin
                    // display_msg("LOOP!");
                    file = fs_copy(sprintf("art\\critters\\%s", frm), chicken_move_frm);
                    // fs_delete(sprintf("art\\critters\\%s", frm));
                    display1("copy", sprintf("art\\critters\\%s", frm));
                end

// $ cat scrname.msg  | grep -bo "Out of Business Sign"
// 48450:Out of Business Sign

                // file = fs_copy("text/english/game/scrname.msg", "text/english/game/scrname.msg");
                // fs_seek(file, 48450);
                // fs_write_string(file, "HELLO");

                // file = fs_copy(sprintf("art\\critters\\%s", "NFVREDAB.FRM"), chicken_move_frm);
                // debug2("copy", sprintf("art\\critters\\%s", "NFVREDAB.FRM"), chicken_move_frm);

                // file = fs_copy(sprintf("art\\critters\\%s", "NFLYNNAB.FRM"), chicken_move_frm);
                // display2("copy", sprintf("art\\critters\\%s", "NFLYNNAB.FRM"), chicken_move_frm);
                
                // TODO read from .ini so it's not in the save game & can be changed
                data.chicken_name = chicken_info.name;

                // TODO - store original AI packets and revert. Right now just hardcode to child.
                // #define AI_PACKET_PROTO_OFFSET (0x0024)
                // #define CHILD_AI_PACKAGE (4)
                // set_proto_data(character_pid, CHILD_AI_PACKAGE);
                // #define AI_CHILD                                (15)
                
                // set_proto_data(character_pid, AI_PACKET_PROTO_OFFSET, CHILD_AI_PACKAGE);

                // Spawn the character
                data.chicken_obj = create_object_sid(character_pid, 0, 0, get_script_id(chicken_info.script));

                // Hmm!
                critter_add_trait(data.chicken_obj, TRAIT_OBJECT, OBJECT_AI_PACKET, AI_CHILD);
                
                // Add them to your party (this allows them to follow you from map to map)
                party_add(data.chicken_obj);

                // Add to the map
                critter_attempt_placement(data.chicken_obj, dude_tile, dude_elevation);
                
                // Destroy the egg
                destroy_object(data.egg_obj);
                data.egg_obj = 0;

                break;
            end
        end
    end
end

procedure drop_p_proc begin
    script_overrides;
    call spawn_chicken;
end

procedure talk_p_proc begin
    if self_obj == data.chicken_obj then
        call dialogue_start("get_items");
end

procedure start begin
    // Has to be reset on map enter - set to the name you give to the chicken
    if self_obj == data.chicken_obj then set_scr_name("The Chicken");

    if not is_started then begin
        is_started = true;
        config = cheatchicken_config;
        data   = cheatchicken_data;
        call setup_dialogue_actions;
    end
end


