#include "gtest/gtest.h"

#include "item.h"
#include "armor.h"
#include "weapon.h"
#include "player.h"
#include "item_test.hpp"
#include "inventory.h"
#include "bubble_sort.h"
#include "visitor_test.hpp"
#include "area_test.hpp"

int main(int argc, char**argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

