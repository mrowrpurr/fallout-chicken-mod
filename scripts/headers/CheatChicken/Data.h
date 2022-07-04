#pragma once

/*
    Management of Cheat Chicken save game data
*/

#define DATA_SAVE_KEY "cheatchicken_data"

// Main Map of Cheat Chicken data.
variable data;

// Is this the first time Cheat Chicken is running in the game?
// e.g. a new game or adding Cheat Chicken during an existing save.
variable is_cheatchicken_first_run = true;

// Load existing save data, if any.
// Otherwise configure data.
procedure load_data begin
    data = load_array(DATA_SAVE_KEY);

    if data then
        is_cheatchicken_first_run = false;
    else begin
        data = {};
        save_array(DATA_SAVE_KEY, data);
    end
end
