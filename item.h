#ifndef __ITEM_H__
#define __ITEM_H__

#include <string>
#include <iostream>
using namespace std;

class Iterator;

class Item {
    private:
        string name;
        int id;
        int type;
    public:
        Item() { };
        Item(string n, int i, int t) {
            name = n;
            id = i;
            type = t;
        }
        ~Item() {};
        bool can_be_equipped() {
            if(id == 1) {
                return true;
            }
            return false;
        }

        string getName() {
            return name;
        }
        int getID() {
            return id;
        }
        int getType() {
            return type;
        }
   
};
#endif

