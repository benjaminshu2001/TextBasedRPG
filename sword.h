#ifndef __SWORD_H__
#define __SWORD_H__

#include "weapon.h"
#include <string>

class Sword : public Weapon {
    public:
        Sword();
        Sword(string n, string d) {
            name = n;
            description = d;
        }
        string getName() {
            return name;
        }
        string getDescription() {
            return description;
        }
        void print() {
             
    private:
        int attackValue;
        //int durability;
        string description;
        string name;
    
};
#endif
