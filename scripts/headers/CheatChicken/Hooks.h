#pragma once

/*
    sfall hooks
*/

procedure description_obj_hook begin
    if ready and player_has_egg and data.egg_obj == get_sfall_arg then begin
        set_sfall_return(get_string_pointer(get_egg_description));
    end
end

procedure register_hooks begin
    register_hook_proc(HOOK_DESCRIPTIONOBJ, description_obj_hook);
end
