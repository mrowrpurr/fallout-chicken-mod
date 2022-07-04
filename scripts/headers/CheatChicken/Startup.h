#pragma once

/*
    Cheat Chicken mod startup
*/

procedure startup begin
    call load_config;
    call load_data;
    call register_hooks;
    ready = true;
    if is_first_run and config.Egg.add_to_inventory_at_start then call give_player_egg;
end
