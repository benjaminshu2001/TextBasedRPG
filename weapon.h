#ifndef __WEAPON_H__
#define __WEAPON_H__

#include "item.h"
#include "visitor.h"

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
        virtual double evaluate() {
            return right->evaluate();
        }
        virtual string stringify() {      
        double evaluate() {
            return right->evaluate();
        }
        string print_name() {
            return left->print_name();
        }
        string stringify() {      
            string s1 = to_string(right->evaluate());
            str = "Weapon: " + left->stringify() + ", Attack: " + s1;
            return str;
        }
        virtual bool get_type() {
            return 1;
        }
        virtual void accept(Visitor* v) {
            v->visit_weapon();
        }
    private:
        Item* left; //name
        Item* right; //attack amount

};
#endif

