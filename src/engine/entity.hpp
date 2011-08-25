/*Stop multiple inclusion */
#ifndef ___entity_inc
#define ___entity_inc 1

#include"SDL.h"
#include"texture.hpp"
#include"vector.hpp"
#include"globals.hpp"
#include"weapon.hpp"

#define E_PLAYER 1
#define E_ENEMY 2
#define E_NEUTRAL 4
#define E_POWERUP 8
#define E_LANDSCAPE 16

#define ENT_ALIGNMENT Sint16

enum ENT_TYPE { ENT_ASTEROID, ENT_PLAYER, ENT_PLAYERSHOT };

#define ENTID_TYPE Uint32

#define ALIGNMENT_ASTEROID 1

class Weapon;
class Entity {
    public:
        ENTID_TYPE ent_id;

        Sint32 health;
        RESTYPE rotation;
        Uint16 experiance_value;
        Uint16 score_value;
        Texture *texture;
        Uint16 accelerating;
        Uint8 size; // 1/2 value always.. gl :)
        int taken_damage;
        Vector *v;
        Weapon *primary;
        Entity *parent;
        Uint32 alignment;
        
        
        void *sector;

        // Public data members go here.
        Entity(); // Constructor

        void setup_entity(void);
        virtual ~Entity(); // Destructor

        virtual int frameupdate(void);

        virtual void update_location(void);
        virtual void render(void);
        virtual void render(Vector *offset);

        virtual int chkDeath(void);
        virtual int chkCollision(Entity *checkme);

        virtual void has_killed(Entity *victim);

        virtual int takeDamage(Sint16 dmg);
        virtual int takeDamage(Sint16 dmg, Entity *who_was_holding_the_gun);
        virtual void death();
        void kill_me_now(void); 
        virtual void log_info(void);
        void move(Sint32 xdir, Sint32 ydir);

    private:
        // Private members go here.

    protected:
        // Protected members go here.
};

#endif
