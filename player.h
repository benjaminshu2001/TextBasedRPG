#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include <string>
#include "inventory.h"
#include "item.h"
using namespace std;

class Player {
    private:
        string name;
        int health;
        int mana;
        Item* held;
        Item* gear;
        Inventory* inv;
    public:
        Player(string n) {
            name = n;
        }
        Player() {};
        ~Player();
        //Player(name, area);
        void attack();
        void block();
        void printInventory(Inventory* inv) {
            for(int i = 0; i < inv->size(); i++) {
                inv->print();
            }
        }
        void useItem(int i);
        void getItem();
        string getName() {
            return name;
        }
};

#endif

