#ifndef __WEAPON_H__
#define __WEAPON_H__

#include "item.h"

#include <iostream>
#include <string>

using namespace std;

class Weapon {
    public:
        Weapon();
        int attack;
        int damage;
    private:
        Item* w;

};
#endif

