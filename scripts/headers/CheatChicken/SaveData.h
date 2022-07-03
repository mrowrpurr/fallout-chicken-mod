#pragma once

/*
    Management of Cheat Chicken save game data
*/

// Main Map of Cheat Chicken data.
variable cheatchicken_data;


// Is this the first time Cheat Chicken is running in the game?
// e.g. a new game or adding Cheat Chicken during an existing save.
variable is_cheatchicken_first_run = true;

// Load existing save data, if any.
// Otherwise configure data.
procedure cheatchicken_load begin

end
