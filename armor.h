#ifndef __ARMOR_H__
#define __ARMOR_H__

#include "item.h"
#include <string>
#include "iterator.h"

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
        Iterator* create_iterator() {
            Iterator* iter = new InvIterator(this);
            return iter;
        }
        virtual double evaluate() {
            return right->evaluate();
        }
        virtual string stringify() {
            string s = to_string(right->evaluate());
            str = "Armor: " + left->stringify() + ", Defense: " + s;
            return str;
        }
    private:
        Item* left; //name
        Item* right; //defense
};
#endif

