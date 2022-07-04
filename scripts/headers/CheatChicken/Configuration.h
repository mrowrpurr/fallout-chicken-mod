#pragma once

#define config_filename "CheatChicken.ini"

// Full representation of the CheatChicken.ini configuration as a Map
variable config;

procedure load_config begin
    variable section_name;

    config = {};
    fix_array(config);

    foreach section_name in get_ini_sections(config_filename) begin
        config[section_name] = get_ini_section(config_filename, section_name);
        fix_array(config[section_name]);
    end
end
