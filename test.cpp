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

    Weapon* it = new Weapon(eq, eq1);
    Armor* ar = new Armor(eq2, eq3);
    
    Armor* test = new Armor(it, ar);
    //Armor* it1 = new Armor("Leather Overalls", 2);
    //Item* it2 = new Item("Health Potion", 2, 3);
    inv->add_element(it);
    inv->add_element(ar);
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
            cout << "A = Inspect items \nB = Organize by Item Type\nC = Equip an item" << endl;
            cin >> choice;
            
            if(choice == 'A' || choice == 'a') {
                cout << iit->current()->stringify() << endl;
                cout << "Here is some starter gear. It has been equipped for you automatically." << endl;


            }
            else if(choice == 'B' || choice == 'b') {
                inv->set_sort_function(new BubbleSort());
                inv->sort();
                inv->print();
            }
            else if(choice == 'C' || choice == 'c') {
                cout << "Which item do you want to equip?" << endl;
                inv->print();
                cin >> choice;
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
                    cout << endl << "Weapon: " << p->get_weapon() << endl;
                }
                if(p->armor_equipped() == false) {
                    cout << endl << "Armor: " << "Nothing is equipped." << endl;
                }
                else {
                    cout << endl << "Armor: " << p->get_armor() << endl;
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
