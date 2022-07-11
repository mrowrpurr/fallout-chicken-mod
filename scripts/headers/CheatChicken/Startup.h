#pragma once

#include "CheatChicken/Config.h"

procedure startup begin
    call load_config;

    // Loop through NPCs and add them to the CURRENT map.
    variable npc_info;
    foreach npc_info in (config.NPCs) begin
        variable obj = create_object(
            npc_info.ProtoID,
            npc_info.Tile,
            0
        );
    end
end
