#ifndef __ITEM_H__
#define __ITEM_H__

#include <string>

class Item {
    private:
        string name;
        int id;
        
    public:
        Item() { };
        Item(string n, int i) {
            name = n;
            id = i;
        }
        ~Item();
        string getName() {
            return name;
        }
        int getID() {
            return id;
        }
}

#endif

