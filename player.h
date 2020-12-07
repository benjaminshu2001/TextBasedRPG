#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include <string>
#include "item.h"
#include "character.h"
#include "armor.h"
#include "weapon.h"

class Player : public Character {
    private:
        std::string name;
        int health;
        int defense;
        int mana;
        int attackDamage;
        Item* weapon;
        Item* armor;
    public:
        Player(string n, int h, int m, int d, int a) {
            name = n;
            health = h;
            mana = m;
            defense = d;
            attackDamage = a;
        }
        //void attack() = 0;
        //void block() = 0;
        void equip_weapon(Item* i) {
            attackDamage += i->get_right()->evaluate();
        }
        void equip_armor(Item* i) {
            defense += i->get_right()->evaluate();
        }
        void print_stats() {
            string s = "Name: " + name + "\n======================\n" + "Health: " + to_string(health) + "\nMana: "
                        + to_string(mana) + "\nAttack: " + to_string(attackDamage) + "\nDefense: " + to_string(defense);
            cout << s << endl;
            
        }
                    
        std::string get_name() {
            return name;
        }
        double get_health() {
            return health;
        }
        double get_mana() {
            return mana;
        }
        double get_attack() {
            return attackDamage;
        }
        double get_defense() {
            return defense;
        }
        
};

#endif

