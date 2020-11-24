#ifndef __INV_ITERATOR_H__
#define __INV_ITERATOR_H__

#include <iostream>
#include "inventory.h"
#include "player.h"
#include "item.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//template <typenamne T, typename U>
class InvIterator : public Inventory {
    private:
        Item* data;
        iter it;

    public:
        void getNext();
        bool isDone();
        Item* getCurrent();
        vector<Item*>::iterator iter;
};
#endif
