# Notes

## Revealing Map Markers

```pascal
variable i;
for i = 0; i <= 48; i++; begin
    mark_on_map(i)
end
```

## Dialogue

- Max 6 options displayed

## Misc

```pascal
Face_Critter(dude_obj, fred);

set_self(fred);
animate_rotation(atoi(fred_info.rotation));
```

```pascal
variable fred_info = config["NPC:Fred"];
variable fred_script_id = get_script_id(fred_info.script);
variable fred = create_object_sid(
    atoi(fred_info.pid),
    atoi(fred_info.tile),
    0,
    fred_script_id
);
set_self(fred);
animate_rotation(atoi(fred_info.rotation));
```

```pascal
// location, description, gvar_index, display_threshold, completed_threshold
// # Kill the Evil Plants
// # Arroyo, GVAR_KILL_EVIL_PLANTS, Quest_Accepted, Quest_Completed
// 1500, 100, 9, 2, 6
//display_msg(GVAR_KILL_EVIL_PLANTS);
set_global_var(GVAR_KILL_EVIL_PLANTS, 6
```
