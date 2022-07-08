#pragma once

#define player_has_egg data.egg_obj

procedure get_egg_description begin
    return message_str(atoi(config.Egg.script_id), MSG_DESCRIPTION_UNFAMILIAR);
end

procedure give_player_egg begin
    if not player_has_egg then begin
        debug2f(
            "Giving player egg... PID %s SCRIPT %s",
            config.Egg.item_pid,
            config.Egg.script_id
        );
        data.egg_obj = create_object_sid(
            atoi(config.Egg.item_pid),
            0, 0,
            atoi(config.Egg.script_id)
        );
        add_obj_to_inven(player_obj, data.egg_obj);
        debug1f("Gave egg to player! (%s)", data.egg_obj);
    end
end
