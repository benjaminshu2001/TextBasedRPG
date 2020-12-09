#include "iterator.h"

#include <iostream>

InvIterator::InvIterator(Item* ptr) : Iterator(ptr) {
   this->iterators = std::stack<Iterator*>();
}

void InvIterator::first() {
    while(!this->iterators.empty()) {
        this->iterators.pop();
    }
    if(this->self_ptr) {
        Iterator* root_itr = this->self_ptr->create_iterator();
        root_itr->first();
        this->iterators.push(root_itr);
    }   
}
void InvIterator::next() {
    Iterator* top_itr = this->iterators.top()->current()->create_iterator();
    top_itr->first();
    this->iterators.push(top_itr);
    while(!this->iterators.empty() && this->iterators.top()->is_done()) {
        this->iterators.pop();
        if(!this->iterators.empty()) {
            this->iterators.top()->next();
        }
    }
}
bool InvIterator::is_done() {
    return this->iterators.empty();
}
Item* InvIterator::current() {
    if(!this->iterators.empty()) {
        return this->iterators.top()->current();
    }
    return nullptr;}
