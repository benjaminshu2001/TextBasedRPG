#ifndef __BUBBLE_SORT_H__
#define __BUBBLE_SORT_H__

#include "sort.hpp"
#include "container.hpp"

class BubbleSort : public Sort {
    public:
        BubbleSort();
        void sort(Container* c);
};
#endif
