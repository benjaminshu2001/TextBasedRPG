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

class InvIterator : public Inventory {
    private:
        Item* data;
        typedef typename vector<T>::iterator iter;
        iter it;

    public:
        void getNext();
        bool isDone();
        Item* getCurrent();
};
#endif
