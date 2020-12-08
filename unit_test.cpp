#include "gtest/gtest.h"

#include "item.h"
#include "armor.h"
#include "iterator.h"
#include "weapon.h"
#include "player.h"
#include "item_test.hpp"
#include "inventory.h"
#include "bubble_sort.h"
#include "iterator_test.hpp"
int main(int argc, char**argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

