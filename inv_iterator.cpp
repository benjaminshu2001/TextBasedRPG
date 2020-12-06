
#include <iostream>
#include "inventory.h"
#include "player.h"
#include "item.h"
#include "iterator.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

InvIterator::InvIterator(Item* ptr) : Iterator(ptr) {
   this->c = left;
}

void InvIterator::first() {
    this->c = left;
}
void InvIterator::next() {
    if(this->c == left) {
        this->c = right;
    }
    else if(this->c == right) {
        this->c = end;
    }
    else {
        this->c = end;
    }
}
bool InvIterator::is_done() {
    if(this->c == end) {
        return true;
    }
    return false;
}
Item* InvIterator::current() {
    if(this->c == left) {
        return this->self_ptr->get_left();
    }
    else if(this->c == right) {
        return this->self_ptr->get_right();
    }
    return nullptr;
}
