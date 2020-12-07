#ifndef __WEAPON_H__
#define __WEAPON_H__

#include "item.h"
#include "iterator.h"

#include <iostream>
#include <string>

using namespace std;

class Weapon : public Item {
    public:
        string str;

        Weapon(Item* l, Item* r) {
            left = l;
            right = r;
        }
        Item* get_left() {
            return left;
        }
        Item* get_right() {
            return right;
        }
        Iterator* create_iterator() {
            Iterator* iter = new InvIterator(this);
            return iter;
        }
        double evaluate() {
            return right->evaluate();
        }
        string stringify() {      
            string s1 = to_string(right->evaluate());
            str = "Weapon: " + left->stringify() + ", Attack: " + s1;
            return str;
        }
    private:
        Item* left; //name
        Item* right; //attack amount

};
#endif
