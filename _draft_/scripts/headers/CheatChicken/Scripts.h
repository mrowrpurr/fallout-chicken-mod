#pragma once

/*
    Helper to get script ids by name
    based on whether fallout is running 2 or et tu.

    TODO - merge into a common CheatChicken.h
*/

#include "Fallout1in2.h"

#define get_script_id(name) (atoi(config["Scripts:Fallout2"][name]) if is_running_fallout2 else atoi(config["Scripts:Fo1in2"][name]))
