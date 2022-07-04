#pragma once

/*
    Extensions to the original KTSMOKE script.

    Cheat Chicken is *evil* and hijacks this script :)
*/

#include "CheatChicken/Debug.h"
#include "CheatChicken/Messages.h"

#define is_script_attached_to_cheat_chicken_or_egg true

variable loaded = false;

procedure load begin
    debug("Egg - I AM ALIVE!");
end

procedure start begin
    if not loaded then begin
        loaded = true;
        call load;
    end
end

procedure look_at_p_proc begin
    script_overrides;
     // TODO: from random group with variants for if you've seen it before and number of game days like it'll get rotten :)
    display_msg(mstr(MSG_LOOKAT_UNFAMILIAR));
end
