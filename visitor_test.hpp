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
    
    inv->add_element(eq);
    inv->add_element(eq1);
    inv->add_element(eq2);
    inv->add_element(eq3);
    inv->add_element(w);
    inv->add_element(a);
    
    Visitor* v = new Visitor();
    for(int i = 0; i < inv->size(); i++) {
        inv->at(i)->accept(v);
    }
    EXPECT_EQ(v->armor_count(), 1);
    EXPECT_EQ(v->weapon_count(), 1);
    EXPECT_EQ(v->equip_count(), 4);
}
TEST(VisitorTest, ArmorVisit) {
    Inventory* inv = new Inventory();
    
    Equip* eq = new Equip("White Shirt");
    Equip* eq1 = new Equip(1);
    Equip* eq2 = new Equip("Leather Overalls");
    Equip* eq3 = new Equip(3);
    Equip* eq4 = new Equip("Leather Sandals");
    Equip* eq5 = new Equip(1);
    Equip* eq6 = new Equip("Blue Shorts");
    Equip* eq7 = new Equip(2);

    Armor* a = new Armor(eq, eq1);
    Armor* a1 = new Armor(eq2, eq3);
    Armor* a2 = new Armor(eq4, eq5);
    Armor* a3 = new Armor(eq6, eq7);
    
    inv->add_element(a);
    inv->add_element(a1);
    inv->add_element(a2);
    inv->add_element(a3);
    
    Visitor* v = new Visitor();
    for(int i = 0; i < inv->size(); i++) {
        inv->at(i)->accept(v);
    }
    EXPECT_EQ(v->armor_count(), 4);
    EXPECT_EQ(v->weapon_count(), 0);

}
TEST(VisitorTest, WeaponVisit) {
    Inventory* inv = new Inventory();
    
    Equip* eq = new Equip("Sword");
    Equip* eq1 = new Equip(1);
    Equip* eq2 = new Equip("Hammer");
    Equip* eq3 = new Equip(3);
    Equip* eq4 = new Equip("Claws");
    Equip* eq5 = new Equip(1);
    Equip* eq6 = new Equip("Mace");
    Equip* eq7 = new Equip(2);

    Weapon* a = new Weapon(eq, eq1);
    Weapon* a1 = new Weapon(eq2, eq3);
    Weapon* a2 = new Weapon(eq4, eq5);
    Weapon* a3 = new Weapon(eq6, eq7);
    
    inv->add_element(a);
    inv->add_element(a1);
    inv->add_element(a2);
    inv->add_element(a3);
    
    Visitor* v = new Visitor();
    for(int i = 0; i < inv->size(); i++) {
        inv->at(i)->accept(v);
    }
    EXPECT_EQ(v->armor_count(), 0);
    EXPECT_EQ(v->weapon_count(), 4);

}
#endif
