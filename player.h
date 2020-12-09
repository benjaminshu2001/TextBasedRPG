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
        bool is_armor_equipped = false;
        bool is_weapon_equipped = false;
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
        bool armor_equipped() {
            if(is_armor_equipped == false) {
                return false;
            }
            return true;
        }
        bool weapon_equipped() {
            if(is_weapon_equipped == false) {
                return false;
            }
            return true;
        }

        void equip_weapon(Item* i) {
            if(is_weapon_equipped == true) {
                if(i->stringify() == weapon->stringify()) {
                    cout << "This weapon has already been equipped." << endl;
                }
                else if(i->stringify() != weapon->stringify()) {
                    attackDamage -= weapon->get_right()->evaluate();
                    weapon = i;
                    attackDamage += i->get_right()->evaluate();
                    is_weapon_equipped = true;
                }
            }
            else {
                attackDamage += i->get_right()->evaluate();
                weapon = i;
                is_weapon_equipped = true;
            }
        }
        void equip_armor(Item* i) {
            if(is_armor_equipped == true) {
                if(i->stringify() == armor->stringify()) {
                    cout << "This armor has already been equipped." << endl;
                }
                else if(i->stringify() != armor->stringify()) {
                    defense -= armor->get_right()->evaluate();
                    armor = i;
                    defense += i->get_right()->evaluate();
                    is_armor_equipped = true;
                }
            }
            else {
                defense += i->get_right()->evaluate();
                armor = i;
                is_armor_equipped = true;
            }
        }    
        void print_stats() {
            string s = "Name: " + name + "\n======================\n" + "Health: " + to_string(health) + "\nMana: "
                        + to_string(mana) + "\nAttack: " + to_string(attackDamage) + "\nDefense: " + to_string(defense);
            cout << s << endl;
            
        }

        std::string get_weapon() {
            string s = weapon->stringify();
            return s;
        }
        std::string get_armor() {
            string s = armor->stringify();
            return s;
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

