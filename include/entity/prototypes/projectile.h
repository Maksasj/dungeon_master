/**
 * projectile
 *
 * @authors
 * Maksimas Jaroslavcevas, Oskaras Vištorskis
 *
 * @brief
 * projectile entity
*/

#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_

#include "../../utils/types.h"
#include "../../utils/logger.h"
#include "../../sprite.h"
#include "../layer_mask.h"
#include "../rotation.h"

//    592 - cobalt arrow horizontal | 736 - cobalt arrow vetical
//    584 - golden arrow horizontal | 728 - golden arrow vetical
//    576 - iron arrow   horizontal | 720 - iron arrow   vetical
//
//    568 - fireball horizontal     | 712 - fireball vetical
//    560 - iceball  horizontal     | 704 - iceball  vetical
//    552 - gemball  horizontal     | 696 - gemball  vetical
//
//    408 - gem staff
//    432 - ice staff
//    456 - fire staff

typedef struct Projectile {
    // Textures
    Sprite* sprite;
    // Texture size
    SpriteSize sprite_size_in_pixels;

    // Vector2 position
    ivec2 position;
    // Vector2 velocity
    ivec2 vel;

    // Layer
    LayerMask layer;

    // facing (UP, RIGHT, LEFT, DOWN)
    Facing facing;

    //void (*update_callback)(Entity* _self, World* _world, Room* _room);
    void (*update_callback)(void*, void*, void*);

    //i32 (*calculate_damage_callback)(Entity* _self);
    i32 (*calculate_damage_callback)(void*);

    //void (*die_callback)(Entity* _self);
    void (*die_callback)(void*);
} Projectile;

/**
 * Updates projectile in worldUpdate
 * 
 * @param _self         existing projectile
 * @param _world        existing world
 * @param _room         existing room
*/
void projectileUpdate(Projectile* _self, void* _room);

/**
 * Destroys projectile
 * 
 * @param _self         existing projectile
*/
void destroyProjectile(Projectile* _self);

void rotateProjectile(Projectile* _projectile, i32 sprite_offset_horizontal, i32 sprite_offset_vetical);

#endif
