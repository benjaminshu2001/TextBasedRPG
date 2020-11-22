#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include "Inventory.h"
#include "Item.h"

class Player {
    private:
        string name;
        int health;
        int mana;
        Item* held;
        Item* gear;
        Inventory* inv;
    public:
        Player();
        ~Player();
        //Player(name, area);
        virtual void attack() = 0;
        virtual void block() = 0;
        void printInventory(Inventory* inv) {
            for(int i = 0; i < inv->size(); i++) {
                inv->print();
            }
        }
        void useItem(int i);
        void getItem();
}
#endif

