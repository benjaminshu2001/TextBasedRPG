#include <iostream>

#include "monster.hpp"
#include "area.hpp"
//#include playerclass
//#include combatsystemclass
//#include inventoryclass
//#include itemclass
 
using namespace std;

int main() {
	
	char input;
	Area* ThisRmPntr;	


	cout << "Hello, welcome to (video game). Enter X to begin or Z to quit." << endl;
	while ((input != 'x') && (input != 'z')) {
		cin >> input;
	}
	if (input == 'z') {
		cout << "Goodbye." << endl;
		return 0;
	}

	cout << "Filling Map" << endl;

	Area* Begin = new Area("Start");
	Begin->fillMap();	
	ThisRmPntr = Begin;

	cout << "Map Filled" << endl << endl << endl;
	
	
	while((ThisRmPntr->referenceCode != "end") && (input != 'z')) {
		ThisRmPntr->CurrentLocation();
		cout << "Area RefCode: " <<  ThisRmPntr->Refcode() << endl;
		cin >> input;
		cout << endl << endl << endl << endl << endl << endl << endl;		
		if (input == 'z') {
			return 0;
		}
		
		if (input == 'i') {
			cout << "Inventory System not yet implemented" << endl;
		}
		
		if ((input == 'a' &&  ThisRmPntr->MoveChecker(1) == true)) {
			ThisRmPntr = ThisRmPntr->West;
			cout << "You have moved west." << endl << endl;
		}
		
		if ((input == 'd') && (ThisRmPntr->MoveChecker(2) == true)) {
			ThisRmPntr = ThisRmPntr->East;
			cout << "You have moved east." << endl << endl;
		}

		if ((input == 'w') && (ThisRmPntr->MoveChecker(4) == true)) {
			ThisRmPntr = ThisRmPntr->North;
			cout << "You have moved north." << endl << endl;
		}

		if ((input == 's') && (ThisRmPntr->MoveChecker(3) == true)) {
			ThisRmPntr = ThisRmPntr->South;
			cout << "You have moved south." << endl << endl;

		}
	}
	cout << "You have reached the end." << endl;
	
	return 0;
}







