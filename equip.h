#ifndef __EQUIP_H__
#define __EQUIP_H__

#include "item.h"
#include "iterator.h"
#include <string>

class Equip : public Item {
    public:
        string str;
        double stat;
        Equip(string st) : Item() {
            str = st;
        }
        Equip(double s) : Item() {
            stat = s;
        }

        Item* get_left() {
            return nullptr;
        }
        Item* get_right() {
            return nullptr;
        }
        //Item* create_iterator() {
            //Iterator* iter = new InvIterator*(this);
            //return iter;
        //}
        virtual double evaluate() {
            return stat;
        }
        virtual string stringify() {
            return str;
        }
};
#endif
