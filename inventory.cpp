#include "inventory.h"
#include <iostream>

using namespace std;

void Inventory::add_element(Item* i) {
    inv.push_back(i);
}

void Inventory::print() {
    for(auto const &i: inv) {
        cout << (i)->getName() << endl;
    }
    cout << endl;
}

void Inventory::sort() {
    sort_function->sort(this);
}

void Inventory::swap(int i, int j) {
    Item* temp = inv.at(i);
    inv.at(i) = inv.at(j);
    inv.at(j) = temp;
}

Item* Inventory::at(int i) {
    return inv.at(i);
}

int Inventory::size() {
    return inv.size();
}

