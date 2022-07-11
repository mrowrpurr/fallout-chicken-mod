#pragma once

#include "IniSettings.h"

export variable EXPORTED_CC_CONFIG_VARIABLE

#define INI_CONFIG "CheatChicken.ini"

variable config

procedure load_config begin
    config = IniSettings_LoadIni(INI_CONFIG, {
        "prefix_types":   true,
        "section_maps":   true,
        "concat_fields":  true,
        "store_array":    true,
        "field_pointers": true
    });
end
