#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include <iostream>
#include "item.h"
#include "player.h"
#include <vector>
#include <string>
using namespace std;

class Inventory : public Item {
    private:
        string name;
        string description;
        vector<Item*> inv;
    public:
        Inventory() {};
        
        Inventory(string n, string des){
            name = n;
            description = des;
        }

        void addItem(Item* i) {
            inv.push_back(i);
        }

        bool isEmpty() {
            if(inv.size() == 0){
                return true;
            } else
                return false;
        }

        int size() {
            return inv.size();
        }

        //Item* at(Item* i) {
          //  return inv.at(i);
       // }

        void print() {
            for(auto const &i: inv) {
                cout << (i)->getName() << ", " << (i)->getID() << endl;
            }
            cout <<endl;
        }
};
#endif
