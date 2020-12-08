#include "player.h"
#include "item.h"
#include "inventory.cpp"
#include "iterator.h"
#include <iostream>
#include <string>
#include "armor.h"
#include "weapon.h"
#include "equip.h"
#include "bubble_sort.cpp"

class InvIterator;

using std::cout;
using std::cin;

int main() {
    string name;   
    char choice;
    string item_choice;
    cout << "Hello, welcome to this text-based rpg game! This is currently named TestWorld." << endl;

    cout << "Original, right? Anyways, if you will, tell us your name." << endl;
    
    cout << "Name: ";
    
    cin >> name;
    cout << endl;

    Player* p = new Player(name, 10, 5, 2, 3);
    
    cout << "Hello, " <<  p->get_name() << ". Hope you enjoy your stay!" << endl;
    cout << "What would you like to do? " << endl;
    cout << "A = continue \nB = View inventory \nC = Check stats \nD = Quit" << endl;
    Inventory* inv = new Inventory();
    Equip* eq = new Equip("Sword");
    Equip* eq1 = new Equip(5);
    Equip* eq2 = new Equip("Leather Overalls");
    Equip* eq3 = new Equip(3);
    Equip* eq4 = new Equip("Mace");
    Equip* eq5 = new Equip(7);
    Equip* eq6 = new Equip("Hammer");
    Equip* eq7 = new Equip(10);
    Equip* eq8 = new Equip("Iron Chestplate");
    Equip* eq9 = new Equip(5);
    Equip* eq10 = new Equip("Chainmail");
    Equip* eq11 = new Equip(10);

    Weapon* it = new Weapon(eq, eq1);
    Armor* ar = new Armor(eq2, eq3);
    Weapon* w = new Weapon(eq4, eq5);
    Weapon* w1 = new Weapon(eq6, eq7);
    Armor* a = new Armor(eq8, eq9);
    Armor* b = new Armor(eq10, eq11);

    Armor* test = new Armor(it, ar);
    Weapon* test1 = new Weapon(w, w1);
    Armor* test2 = new Armor(a, b);
    //Armor* it1 = new Armor("Leather Overalls", 2);
    //Item* it2 = new Item("Health Potion", 2, 3);
    inv->add_element(it);
    inv->add_element(ar);
    inv->add_element(w);
    inv->add_element(w1);
    inv->add_element(a);
    inv->add_element(b);
    //inv->add_element(it1);
    //inv->add_element(it2);
    
    InvIterator* iit = new InvIterator(test);
    
    while(cin >> choice) {
        if(choice == 'A' || choice == 'a') {
            cout << "WIP, but this should continue the story!" << endl;
            cout << "Here is some starter gear. It has been equipped for you automatically." << endl;
                p->equip_armor(ar);
                p->equip_weapon(it);

        }
        else if(choice == 'B'|| choice == 'b') {
            cout << "Viewing inventory..." << endl;
            cout << "Here are the items that you currently have in your inventory: " << endl;
            inv->print();
            cout << "A = List items \nB = Organize by Item Type\nC = Equip an item" << endl;
            cin >> choice;
            
            if(choice == 'A' || choice == 'a') {
                cout << iit->current()->stringify() << endl;
                inv->print();
            }
            else if(choice == 'B' || choice == 'b') {
                inv->set_sort_function(new BubbleSort());
                inv->sort();
                inv->print();
            }
            else if(choice == 'C' || choice == 'c') {
                cout << "Which item do you want to equip? Type the name of the equipment." << endl;
                inv->print();
                cin.ignore();
                getline(cin, item_choice);
                if(item_choice == "Mace") {
                    p->equip_weapon(w);
                }
                else if(item_choice == "Sword") {
                    p->equip_weapon(it);
                }
                else if(item_choice == "Hammer") {
                    p->equip_weapon(w1);
                } 
                else if(item_choice == "Iron Chestplate") {
                    p->equip_armor(a);
                }
                else if(item_choice == "Chainmail") {
                    p->equip_armor(b);
                }
            }
        }
        else if(choice == 'C' || choice == 'c') {
            p->print_stats();
            cout << "A = Check your currently equipped items\nB = Back" << endl;
            cin >> choice;
            if(choice == 'A' || choice == 'a') {
                if(p->weapon_equipped() == false) {
                    cout << endl << "Weapon: " << "Nothing is equipped." << endl;
                }
                else if(p->weapon_equipped() == true){
                    cout << endl << p->get_weapon() << endl;
                }
                if(p->armor_equipped() == false) {
                    cout << endl << "Armor: " << "Nothing is equipped." << endl;
                }
                else {
                    cout << endl << p->get_armor() << endl;
                }
            }
        }
        else if(choice == 'D') {
            cout << "Goodbye!" << endl;
            exit(1);
        }
        else {
            cout << "Invalid input, please try again." << endl;
        }
        cout << endl << "What would you like to do? " << endl;
        cout << "A = continue \nB = View inventory \nC = Check stats \nD = Quit" << endl;
    }

return 0;

}
