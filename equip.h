#ifndef __EQUIP_H__
#define __EQUIP_H__

#include "item.h"
#include "iterator.h"
#include <string>
#include "visitor.h"

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
        Iterator* create_iterator() {
            Iterator* iter = new NullIterator(this);
            return iter;
        }
        virtual double evaluate() {
            return stat;
        }
        virtual string stringify() {
            return str;
        }
        virtual bool get_type() {
            return 0;
        }
        virtual string print_name() {
            return str;
        }
        virtual void accept(Visitor* v) {
            v->visit_equip();
        }
};
#endif
