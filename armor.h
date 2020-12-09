#ifndef __ARMOR_H__
#define __ARMOR_H__

#include "item.h"
#include <string>


using namespace std;

class Armor : public Item {
    public:
        string str;
        Armor(Item* l, Item* r) {
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
        string print_name() {
            return left->print_name();
        }
        virtual string stringify() {
            string s = to_string(right->evaluate());
            str = "Armor: " + left->stringify() + ", Defense: " + s;
            return str;
        }
        virtual bool get_type() {
            return 0;
        }
        virtual void accept(Visitor* v) {
            v->visit_armor();
        }
    private:
        Item* left; //name
        Item* right; //defense
};
#endif

