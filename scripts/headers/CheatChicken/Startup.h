#pragma once

/*
    Cheat Chicken mod startup
*/

variable ready = false;

procedure startup begin
    call load_config;
    call load_data;
    ready = true;
end
