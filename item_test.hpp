#ifndef __ITEM_TEST_HPP__
#define __ITEM_TEST_HPP__

#include "gtest/gtest.h"
#include "item.h"
#include "armor.h"
#include "weapon.h"
#include "equip.h"
#include "inventory.h"
#include "bubble_sort.h"

TEST(ItemTest, EquipTest) {
    Inventory* inv = new Inventory();
    Equip* e1 = new Equip("Baseball Bat");
    Equip* e2 = new Equip(2);
    Armor* a = new Armor(e1, e2);
    inv->add_element(a);
    EXPECT_EQ(inv->size(), 1);
}

TEST(ItemTest, ArmorTest) {
    Inventory* inv = new Inventory();
    Equip* e1 = new Equip("Overalls");
    Equip* e2 = new Equip(1);
    Equip* e3 = new Equip("Leather Cap");
    Equip* e4 = new Equip(1);
    Armor* a = new Armor(e1, e2);
    Armor* b = new Armor(e3, e4);

    Armor* test = new Armor(a,b);
    inv->add_element(a);
    inv->add_element(b);
    EXPECT_EQ(a->stringify(), "Armor: Overalls, Defense: 1.000000");
    EXPECT_EQ(a->evaluate(), 1);
    EXPECT_EQ(b->stringify(), "Armor: Leather Cap, Defense: 1.000000");
    EXPECT_EQ(b->evaluate(), 1);
    EXPECT_EQ(inv->size(), 2);
}

TEST(ItemTest, WeaponTest) {
    Inventory* inv = new Inventory();
    Equip* e1 = new Equip("Sword");
    Equip* e2 = new Equip(3);
    Equip* e3 = new Equip("Mace");
    Equip* e4 = new Equip(3);
    Weapon* a = new Weapon(e1, e2);
    Weapon* b = new Weapon(e3, e4);
    Weapon* test = new Weapon(a, b);
    inv->add_element(a);
    inv->add_element(b);
    EXPECT_EQ(a->stringify(), "Weapon: Sword, Attack: 3.000000");
    EXPECT_EQ(a->evaluate(), 3);
    EXPECT_EQ(b->stringify(), "Weapon: Mace, Attack: 3.000000");
    EXPECT_EQ(b->evaluate(), 3);
}

TEST(ItemTest, ZeroArmorTest) {
    Inventory* inv = new Inventory();
    Equip* e1 = new Equip("Overalls");
    Equip* e2 = new Equip(0);
    Equip* e3 = new Equip("Leather Cap");
    Equip* e4 = new Equip(0);
    Armor* a = new Armor(e1, e2);
    Armor* b = new Armor(e3, e4);

    Armor* test = new Armor(a,b);
    inv->add_element(a);
    inv->add_element(b);
    EXPECT_EQ(a->stringify(), "Armor: Overalls, Defense: 0.000000");
    EXPECT_EQ(a->evaluate(), 0);
    EXPECT_EQ(b->stringify(), "Armor: Leather Cap, Defense: 0.000000");
    EXPECT_EQ(b->evaluate(), 0);
    EXPECT_EQ(inv->size(), 2);
}

TEST(InventoryTest, WholeInventoryTest) {
    Inventory* inv = new Inventory();
    Equip* e1 = new Equip("ODM Helmet");
    Equip* e2 = new Equip(50);
    Equip* e5 = new Equip("ODM Chestplate");
    Equip* e6 = new Equip(150);
    Equip* e7 = new Equip("ODM Leggings");
    Equip* e8 = new Equip(125);
    Equip* e9 = new Equip("ODM Boots");
    Equip* e10 = new Equip(100);
    Armor* odm_helmet = new Armor(e1, e2);
    Armor* odm_chest = new Armor(e5, e6);
    Armor* odm_leg = new Armor(e7, e8);
    Armor* odm_boot = new Armor(e9, e10);
    Equip* e3 = new Equip("Thunder Spear");
    Equip* e4 = new Equip(150);
    Weapon* spear = new Weapon(e3, e4);
    inv->add_element(odm_helmet);
    inv->add_element(odm_chest);
    inv->add_element(odm_leg);
    inv->add_element(spear);
    inv->add_element(odm_boot);
    inv->print();

    cout << "Swapping helmet and leggings..." << endl << endl;
    inv->swap(0, 2);
    inv->print();

    cout << "Item at index 3: " << inv->at(3)->stringify() << endl;
    cout << "Size of inventory: " << inv->size() << endl;
    cout << "Sorting by item type..." << endl;
    inv->set_sort_function(new BubbleSort());
    inv->sort();
    cout << "Printing by item type..." << endl << endl;
    inv->print();
    EXPECT_EQ(inv->size(), 5);
}

TEST(PlayerTest, WholePlayerTest) {
    Player* p = new Player("Levi", 10, 10, 5, 5);
    Inventory* inv = new Inventory();
    Equip* e1 = new Equip("ODM Helmet");
    Equip* e2 = new Equip(50);
    Equip* e5 = new Equip("ODM Chestplate");
    Equip* e6 = new Equip(150);
    Equip* e7 = new Equip("ODM Leggings");
    Equip* e8 = new Equip(125);
    Equip* e9 = new Equip("ODM Boots");
    Equip* e10 = new Equip(100);
    Armor* odm_helmet = new Armor(e1, e2);
    Armor* odm_chest = new Armor(e5, e6);
    Armor* odm_leg = new Armor(e7, e8);
    Armor* odm_boot = new Armor(e9, e10);
    Equip* e3 = new Equip("Thunder Spear");
    Equip* e4 = new Equip(150);
    Weapon* spear = new Weapon(e3, e4);
    inv->add_element(odm_helmet);
    inv->add_element(odm_chest);
    inv->add_element(odm_leg);
    inv->add_element(spear);
    inv->add_element(odm_boot);
    inv->print();

    p->equip_weapon(spear);
    p->equip_armor(odm_helmet);
    p->equip_armor(odm_chest);
    p->equip_armor(odm_leg);
    p->equip_armor(odm_boot);
    
    EXPECT_EQ(p->get_attack(), 155); 
}

TEST(PlayerTest, NoEquipTest) {
    Player* p = new Player("Test", 10, 10, 3, 3);
    Inventory* inv = new Inventory();
    if(p->weapon_equipped() == false) {
        cout << "No weapon is equipped." << endl;
    }
    
    if(p->armor_equipped() == false) {
        cout << "No armor is equipped." << endl;
    }
}
#endif
