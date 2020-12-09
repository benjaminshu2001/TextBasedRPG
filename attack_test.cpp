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
class Iterator;

using std::cout;
using std::cin;

int main() {
    string name = "Test Name";
    int h = 10;
    int d = 2;
    int m;
    int atkdmg;
    int monster_def;

    cout << "(TEST) enter atkdmg: ";
    cin >> atkdmg;

    cout << endl << "(TEST) enter monster_def: ";
    cin >> monster_def;

    cout << endl << "(TEST) enter mana: ";
    cin >> m;
    cout << endl;

    Player* p = new Player(name, h, m, d, atkdmg);
    cout << p->AttackClient(monster_def) << endl;
	
    
return 0;

}
