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
    string name = "Test Name"
    int h = 10;
    int d = 2;
    int m = 1;
    int atkdmg = 10;
    int monster_def = 10

    Player* p = new Player(name, h, d, m, atkdmg);
    p->AttackClient(monster_def);

    
return 0;

}
