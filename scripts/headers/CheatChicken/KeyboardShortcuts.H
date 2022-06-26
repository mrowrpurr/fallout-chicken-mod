#ifndef CHEATCHICKEN_KEYBOARDSHORTCUTS_H
#define CHEATCHICKEN_KEYBOARDSHORTCUTS_H

#include "..\headers\sfall\sfall.h"
#include "..\headers\sfall\dik.h"

procedure on_keypress begin
    variable released := get_sfall_arg_at(0);
    variable dx_keycode := get_sfall_arg_at(1);

    if released and dx_keycode == DIK_K and (key_pressed(DIK_LSHIFT) or key_pressed(DIK_RSHIFT)) then begin
        message_box("Hello world! You pressed SHIFT+K");
    end
end

#define listen_for_keyboard_shortcuts register_hook_proc(HOOK_KEYPRESS, on_keypress)

#endif
