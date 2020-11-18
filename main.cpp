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
	string LastRmRC;

	cout << "Hello, welcome to (video game). Enter X to begin or Z to quit." << endl;
	while ((input != 'x') && (input != 'z')) {
		cin >> input;
	}
	if (input == 'z') {
		cout << "Goodbye." << endl;
		return 0;
	}

	cout << "Filling Map" << endl;

	Area* Begin = new Area(0, "Start", "You are in the first room.");
	Begin->fillMap();	
	ThisRmPntr = Begin;
	LastRmRC = Begin->Refcode();
	ThisRmPntr->referenceCode = ThisRmPntr->Refcode() + "(Here)";

	cout << "Map Filled" << endl << endl << endl;
	
	
	while((ThisRmPntr->referenceCode != "end") && (input != 'z')) {
		ThisRmPntr->CurrentLocation();
		cout << "Area RefCode: " <<  ThisRmPntr->Refcode() << endl;
		cin >> input;
		cout << endl << endl << endl << endl << endl << endl << endl;		
		if (input == 'z') {
			return 0;
		}
		
		else if (input == 'i') {
			cout << "Inventory System not yet implemented" << endl;
		}
		
		else if (input == 'm') {
			Begin->PrintMap();
			cout << endl << endl;
		}

		else if ((input == 'a' &&  ThisRmPntr->MoveChecker(1) == true)) {
			ThisRmPntr->referenceCode = LastRmRC;
			LastRmRC = ThisRmPntr->West->Refcode();
			ThisRmPntr = ThisRmPntr->West;
			ThisRmPntr->referenceCode = ThisRmPntr->referenceCode + "(Here)";
			cout << "You have moved west." << endl << endl;
		}
		
		else if ((input == 'd') && (ThisRmPntr->MoveChecker(2) == true)) {
			ThisRmPntr->referenceCode = LastRmRC;
			LastRmRC = ThisRmPntr->East->Refcode();
			ThisRmPntr = ThisRmPntr->East;
			ThisRmPntr->referenceCode = ThisRmPntr->referenceCode + "(Here)";
			cout << "You have moved east." << endl << endl;
		}

		else if ((input == 'w') && (ThisRmPntr->MoveChecker(4) == true)) {
			ThisRmPntr->referenceCode = LastRmRC;
			LastRmRC = ThisRmPntr->North->Refcode();
			ThisRmPntr = ThisRmPntr->North;
			ThisRmPntr->referenceCode = ThisRmPntr->referenceCode + "(Here)";
			cout << "You have moved north." << endl << endl;
		}
								
		else if ((input == 's') && (ThisRmPntr->MoveChecker(3) == true)) {
			ThisRmPntr->referenceCode = LastRmRC;
			LastRmRC = ThisRmPntr->South->Refcode();
			ThisRmPntr = ThisRmPntr->South;
			ThisRmPntr->referenceCode = ThisRmPntr->referenceCode + "(Here)";
			cout << "You have moved south." << endl << endl;		
		}
		
		else {
			cout << "Invalid Input!" << endl;
		}

	}

	cout << "You have reached the end." << endl;
	
	return 0;
}







