#ifndef __ITERATOR_HPP__
#define __ITERATOR_HPP__

#include <stack>

#include "item.h"
#include "container.hpp"

class Item;

enum ChildIndicator { left, right, end };

class Iterator {
    protected:
        Item* self_ptr;

    public:
        Iterator(Item* ptr) { 
            this->self_ptr = ptr; 
        }

        virtual void first() = 0;
        virtual void next() = 0;
        virtual bool is_done() = 0;
        virtual Item* current() = 0;
};

class InvIterator : public Iterator {
    protected:
        ChildIndicator c;

    public:
        InvIterator(Item* ptr);
        
        void first();
        void next();
        bool is_done();
        Item* current();
};
class NullIterator : public Iterator {
    public:
        NullIterator(Item* ptr) : Iterator(ptr) {}

        void first() {}
        void next() {}
        bool is_done() {
            return true;
        }
        Item* current() { 
            return nullptr; 
        }
};
#endif
