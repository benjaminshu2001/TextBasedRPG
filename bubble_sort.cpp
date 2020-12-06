#include "BubbleSort.h"

#include <iostream>
#include "sort.hpp"

BubbleSort::BubbleSort() {}

void BubbleSort::sort(Container* c) {
    int i, j;
    for(i = 0; i < c->size(); i++) {
        for(j = 0; j < c->size() - 1; j++) {
            if(c->at(j)->evaluate() > c->at(j+1)->evaluate()) {
                c->swap(j, j+1);
            }
        }
    }
}
