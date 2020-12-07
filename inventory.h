#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include <iostream>
#include "container.hpp"

#include <vector>
#include <string>



class Inventory : public Container {
    private:
        std::vector<Item*> inv;
    public:
        Inventory() {};  
        void add_element(Item* i);
        bool isEmpty();
        int size();
        Item* at(int i);           
        void print();
        void sort();
        void swap(int, int);


  
        
};
#endif
