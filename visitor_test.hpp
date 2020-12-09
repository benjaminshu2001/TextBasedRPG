#ifndef __VISITOR_TEST_H__
#define __VISITOR_TEST_H__

#include <iostream>
#include "visitor.h"
#include "item.h"
#include "inventory.h"
#include "weapon.h"
#include "armor.h"
#include "container.hpp"

TEST(VisitorTest, EquipVisit) {
    Inventory* inv = new Inventory();
    
    Equip* eq = new Equip("Sword");
    Equip* eq1 = new Equip(5);
    Equip* eq2 = new Equip("Leather Overalls");
    Equip* eq3 = new Equip(3);
    
    Weapon* w = new Weapon(eq, eq1);
    Armor* a = new Armor(eq2, eq3);
    
    inv->add_element(w);
    inv->add_element(a);
    
    Visitor* v = new Visitor();
    for(int i = 0; i < inv->size(); i++) {
        inv->at(i)->accept(v);
    }
    EXPECT_EQ(v->armor_count(), 1);
    EXPECT_EQ(v->weapon_count(), 1);
};
#endif
