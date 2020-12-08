#include "bubble_sort.h"

#include <iostream>
//#include "sort.hpp"

BubbleSort::BubbleSort() {}

void BubbleSort::sort(Container* c) {
    int i, j;
    for(i = 0; i < c->size(); i++) {
        for(j = 0; j < c->size() - 1; j++) {
            if(c->at(j)->stringify() > c->at(j+1)->stringify()) {
                c->swap(j, j+1);
            }
        }
    }
}
