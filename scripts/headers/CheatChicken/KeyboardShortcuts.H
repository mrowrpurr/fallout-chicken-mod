#ifndef CHEATCHICKEN_KEYBOARDSHORTCUTS_H
#define CHEATCHICKEN_KEYBOARDSHORTCUTS_H

#include "..\headers\sfall\sfall.h"
#include "..\headers\sfall\dik.h"
#include "..\headers\CheatChicken\Configuration.H"

procedure on_keypress begin
    variable released   := get_sfall_arg_at(0);
    variable dx_keycode := get_sfall_arg_at(1);
    variable config     := get_keyboard_shortcut_config;
    
    if released and dx_keycode == config.shortcut then begin
        message_box("You pressed the configured key!");
    end
end

#define listen_for_keyboard_shortcuts register_hook_proc(HOOK_KEYPRESS, on_keypress)

#endif
