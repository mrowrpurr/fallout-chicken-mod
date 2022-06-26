#include "..\headers\sfall\sfall.h"
#include "..\headers\sfall\dik.h"

procedure on_keypress begin
    variable args := get_sfall_args;
    variable dx   := args[1];
    variable vk   := args[2];
    display_msg("DX: " + dx + " VK " + vk);
end

#define listen_for_keyboard_shortcuts register_hook_proc(HOOK_KEYPRESS, on_keypress)
