# Dungeon Master
Dungeon Master - Game Boy Advance(GBA) rogue like game written specially for [GBA Jam 2022](https://itch.io/jam/gbajam22)


**[Warning]** Recently we changed compiler and overall approach, now we will use devkitadv, look **Setup** section for more information.
There's not a lot documentation about **devkitadv**, and overall looking at new approach it is more low level, but its fine cause we will have more controls on hardware. For more practice I suggest watch this [video](https://www.youtube.com/watch?v=6ecgELrwAnQ&t=387s) , or look on this [repository](https://github.com/3DSage/GBA_Mode_5_Starter) (as I think pretty good example of devkitadv based project)

## Todo list
- [ ] Graphics
    - [ ] Create main graphic atlas
- [ ] Game Logic
    - [ ] Battle system
    - [ ] World interaction
    - [ ] Item logic
- [ ] Game Environment
    - [ ] Design game world
        - [ ] Enemies
        - [ ] Environment
    - [ ] Graphic style

## Key concepts
- Player
    - Searching for items
    - Fighting Mobs
    - Clearing dungeon
- Traps
    - Summons Mobs
    - Gives debuffs, damages player (Spikes, ex.)
- Enemies
    - Fight against player
    - Drop items after death
        - *armor*
        - *weapons*
        - *powerups*
- Powerups
    - Heal
    - Speed
    - Strength
    - Durability
- **[Design] Inventory**
- Player goes deeper in to dungeon. (Dungeon Floor System).
- Boss
    - After killing him, game is finished.

## Setup

**devkitadv** - Software Development Kit for the Nintendo(tm) Gameboy Advance(tm) based on GCC.

**[Note] devkitadv already contains gcc, if you already have one, try to delete gcc from bin folder of devkitadv package. Or simply temporary remove mingw's gcc from PATH environment variable.**

Follow these few steps to install development environment on your local machine:
- Dowloand full packed **devkitadv** package. [link](https://drive.google.com/file/d/1e5EfY6YxEkvzd7Fgp4rJgkPiA7NVlmBN/view?usp=sharing)
- Unzip archive in preferred place.
- *[Optional] add %YourChosenPath%/devkitadv/bin to PATH environment variables*
- *[Optional] test your setup by building test project*
- Setup is finished 😊
