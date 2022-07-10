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

## Characters

### Fallout 1

#### Starting Tiles (v13ent)



#### NPC Protos

- Purple Robes - 16777228
- Blue Robes - 16777429
- Power Armor - 16777341
- Robo Brain - 16777285
- Mr Handy - 16777529
- Doctor - 16777517
- Green Mohawk Chick - 16777538

### Fallout 2

#### Starting Tiles (artemple)

- 18083
- 18886
- 18294
- 18894
- 19291

#### NPC Protos

- Green Mohawk Chick - 16777365
- Scientist - 16777511
- Mr Handy - 16777388
- Casino Bouncer Blue - 16777654
- Casino Bouncer Grey - 16777655
- Purple Robes - 16777392
- Upclass Citizen - 16777310
- Power Armor - 16777406
- Police Officer - 16777353
