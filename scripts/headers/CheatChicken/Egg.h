#pragma once

#define player_has_egg data.egg

procedure give_player_egg begin
    if not player_has_egg then begin
        debug1("Giving player egg... %s", config.Egg.item_pid);
        data.egg = create_object(atoi(config.Egg.item_pid), 0, 0);
        add_obj_to_inven(player_obj, data.egg);
        debug1("Gave egg to player! (%s)", data.egg);
    end
end
