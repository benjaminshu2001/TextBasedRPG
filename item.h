#ifndef __ITEM_H__
#define __ITEM_H__

#include <string>
#include <iostream>
#include "visitor.h"

class Iterator;

class Item {
    public:
        Item() { };
        
        virtual std::string stringify() = 0;
        virtual double evaluate() = 0;
        virtual Item* get_left() = 0;
        virtual Item* get_right() = 0;    
        virtual bool get_type() = 0;
        virtual std::string print_name() = 0;
        virtual void accept(Visitor*) = 0;
};
#endif

