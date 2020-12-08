#ifndef __ITEM_H__
#define __ITEM_H__

#include <string>
#include <iostream>
#include "iterator.h"


class Iterator;

class Item {
    public:
        Item() { };
        
        virtual std::string stringify() = 0;
        virtual double evaluate() = 0;
        //virtual Iterator* create_iterator() = 0;
        virtual Item* get_left() = 0;
        virtual Item* get_right() = 0;
   
};
#endif

