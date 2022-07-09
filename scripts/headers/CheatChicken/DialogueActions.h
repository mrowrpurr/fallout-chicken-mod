#pragma once

procedure give_guns begin
    add_obj_to_inven(dude_obj, create_object(PID_SHOTGUN, 0, 0));
end

procedure setup_dialogue_actions begin
    AddNamedHandler("give_guns", give_guns);
end
