#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include "Inventory.h"
#include "Item.h"

class Player {
    private:
        int health;
        int mana;
        Item* held;
        Item* gear;
        Inventory* inv;
    public:
        virtual void attack() = 0;
        virtual void block() = 0;
        void accessInventory(Inventory* inv);
        void useItem(int i);

}
#endif

