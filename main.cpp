#include "player.h"
#include "item.h"
#include "inventory.cpp"
#include "iterator.h"

#include <iostream>
#include <string>

using namespace std;

int main() {
    string name;   
    char choice;

    cout << "Hello, welcome to this text-based rpg game! This is currently named TestWorld." << endl;

    cout << "Original, right? Anyways, if you will, tell us your name." << endl;
    
    cout << "Name: ";
    
    cin >> name;
    cout << endl;

    Player* p = new Player(name);
    
    cout << "Hello, " <<  p->getName() << ". Hope you enjoy your stay!" << endl;
    cout << "What would you like to do? " << endl;
    cout << "A = continue \nB = View inventory \nC = Quit" << endl;
    Inventory* inv = new Inventory();
    Item* it = new Item("Sword", 1, 1);
    
    Item* it1 = new Item("Leather Overalls", 2, 2);
    inv->add_element(it);
    inv->add_element(it1);
    
    while(cin >> choice) {
        if(choice == 'A' || choice == 'a') {
            cout << "WIP, but this should continue the story!" << endl;     
        }
        else if(choice == 'B'|| choice == 'b') {
            cout << "Viewing inventory..." << endl;
            cout << "Here are the items that you currently have in your inventory: " << endl;
            inv->print();
        }
        else if(choice == 'C') {
            cout << "Goodbye!" << endl;
            exit(1);
        }
        else {
            cout << "Invalid input, please try again." << endl;
        }
    }

return 0;
}
