#include "player.h"
//#include "item.h"
//#include "inventory.h"

#include <iostream>
using namespace std;

int main() {
    string name;   


    cout << "Hello, welcome to this text-based rpg game! This is currently named TestWorld." << endl;

    cout << "Original, right? Anyways, if you will, tell us your name." << endl;
    
    cout << "Name: ";
    
    cin >> name;
    cout << endl;

    Player* p = new Player(name);

    cout << "Hello, " <<  p->getName() << ". Hope you enjoy your stay!" << endl;
    
    Inventory* inv = new Inventory();
    Item* it = new Item("Sword", 1, 1);

    Item* it1 = new Item("Leather Overalls", 2, 2);
    inv->addItem(it);
    inv->addItem(it1);
    
    cout << "Here are the items that you currently have in your inventory: " << endl;
    inv->print();

    return 0;
}
