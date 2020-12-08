#include <iostream>

#include "monster.hpp"
#include "area.hpp"
#include "player.h"
//#include combatsystemclass
#include "inventory.cpp"
#include "item.h"
#include "iterator.h"
//#include "inv_iterator.cpp"
#include "bubble_sort.cpp"
#include "equip.h"
 
class InvIterator;

using namespace std;

char startMenu(Area* Start);
Player* createChar();
void inventoryMenu(Inventory* I, InvIterator *ITT);
void clearScreen();


int main() {
	
	char input = 0;
	Area* ThisRmPntr = 0;
	Area* Begin = 0;	
	string LastRmRC = "";
	Player* Protagonist = 0;	
	Inventory* Inv = 0;
	

	input = startMenu(ThisRmPntr);
	if ((input == 'z') || (input == 'Z')) {
		cout << "Goodbye." << endl;
		return 0;
	}

	ThisRmPntr = ThisRmPntr->beginMap();
	LastRmRC = ThisRmPntr->Refcode();
	ThisRmPntr->referenceCode = ThisRmPntr->Refcode() + "(Here)";
	Begin = ThisRmPntr;

/*

	cout << "Filling Map" << endl;

	Area* Begin = new Area(0, "Start", "You are standing in front of the entrance into the dungeon.");
	Begin->fillMap();	
	ThisRmPntr = Begin;
	LastRmRC = Begin->Refcode();
	ThisRmPntr->referenceCode = ThisRmPntr->Refcode() + "(Here)";

	cout << "Map Filled" << endl << endl << endl;

*/

	Protagonist = createChar();
	Inv = new Inventory();

	Equip* eq = new Equip("Wooden Sword");
	Equip* eq1 = new Equip(5);
	Equip* eq2 = new Equip("Leather Overalls");
	Equip* eq3 = new Equip(3);

	Equip* A = new Equip("A");
	Equip* A1 = new Equip(1);
	Equip* B = new Equip("B");
	Equip* B1 = new Equip(2);
	Equip* C = new Equip("C");
	Equip* C1 = new Equip(3);
	Equip* D = new Equip("D");
	Equip* D1 = new Equip(4);
	Equip* E = new Equip("E");
	Equip* E1 = new Equip(5);
	Equip* F = new Equip("F");
	Equip* F1 = new Equip(6);


	Weapon* it = new Weapon(eq, eq1);
	Armor* ar = new Armor(eq2, eq3);
    
	Weapon* A2 = new Weapon(A, A1);
	Weapon* B2 = new Weapon(B, B1);
	Weapon* C2 = new Weapon(C, C1);
	Armor* D2 = new Armor(D, D1);
	Armor* E2 = new Armor(E, E1);
	Armor* F2 = new Armor(F, F1);

	Inv->add_element(E2);
	Inv->add_element(B2);
	Inv->add_element(D2);
	Inv->add_element(C2);	
	Inv->add_element(A2);
	Inv->add_element(F2);

	Armor* test = new Armor(it, ar);	
	Inv->add_element(it);
        Inv->add_element(ar);	
	
	Protagonist->equip_armor(Inv->at(1));
	Protagonist->equip_weapon(Inv->at(0));

	InvIterator* iit = new InvIterator(test);
	

	while((ThisRmPntr->referenceCode != "end(Here)") && (input != 'z')) {
		ThisRmPntr->CurrentLocation();
		cout << "Area RefCode: " <<  ThisRmPntr->Refcode() << endl;
		cin >> input;
		cout << endl << endl << endl << endl << endl << endl << endl;		
		if ((input == 'z') || (input == 'Z')) {
			cout << "Goodbye, " << Protagonist->get_name() << "."  << endl;
			return 0;
		}
		
		else if ((input == 'i') || (input == 'I')) {
			if (Inv->size() == 0) {
				cout << "Your inventory is empty!" << endl << endl; 
			}
			else {
				inventoryMenu(Inv, iit);
				cout << endl << endl;	
			}
		}
		
		else if ((input == 'm') || (input == 'M')) {
			Begin->PrintMap();
			cout << endl << endl;
		}
		
		else if ((input == 'e') || (input == 'E')) {
			Protagonist->print_stats();
			cout << "Equipped Weapon: ";
//			Protagonist->get_weapon();
			cout << endl << "Equipped Armor: ";
//			Protagonist->get_armor(); 
			cout << endl << endl;
		}

		else if ((input == 'y') && (ThisRmPntr->Enemy != 0)) {
			cout <<	ThisRmPntr->Enemy->desc() << endl;
		}

		else if ((input == 'x') && (ThisRmPntr->Enemy != 0)) {
			if (ThisRmPntr->Enemy->health < 0) {
				cout << "Monster is already dead!" << endl;
			}
			else {
				cout << "Combat System not yet implemented!" << endl;
			}	
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

	cout << "You have reached the end. Game Over." << endl;
	
	return 0;
}




char startMenu(Area* AreaStart) {
	char input; 

	clearScreen();

	cout << " ~*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*~ " << endl;
	cout << "~                                                             ~ " << endl;
	cout << "~	 	  Hello, welcome to (video game).	      ~ " << endl;
	cout << "~ 		  Enter X to begin or Z to quit.	      ~	" << endl;
	cout << "~        By: Dennis Chen, Benjamin Shu, and David Kim	      ~ " << endl;
	cout << "~							      ~ " << endl;
	cout << " ~*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*~ "  << endl;
	while ((input != 'x') && (input != 'z')) {						
		cin >> input;				
	}										
	cout << endl << endl << endl;
	return input;
}


Player* createChar() {
	string PName;

	clearScreen();	

	cout << " ~*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*~ " << endl;
	cout << "~                                                           ~ " << endl;
	cout << "~           Will you tell us your name, stranger?           ~ " << endl;
	cout << "~							    ~ " << endl;
	cout << " ~*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*~ " << endl;
	cout << "Player Name: ";
	cin >> PName;	
	cout << endl << endl;
	Player* Temp = new Player(PName, 10, 5, 2 ,3);

	clearScreen();

	cout << "Hello " << Temp->get_name() << ". We hope you enjoy your stay!" << endl;
	return Temp;
}

void inventoryMenu(Inventory *I, InvIterator* IIT) {
	char choice = 0;

	cout << "==============================================================" << endl;
	cout << "Here are the items that you currently have in your inventory: " << endl << endl;
        I->print();
	cout << "==============================================================" << endl;



	while ((choice != 'z') && (choice != 'Z')) {
		cout << "Enter A to list inventory items, B to organize by Item Type, C to equip an item, or Z to return to main screen." << endl;
		cin >> choice;
		cout << endl << endl << endl;


		if ((choice == 'a') || (choice == 'A')) {
			cout << "==============================================================" << endl;
			cout << "Here are the that items you currently have in your inventory: " << endl << endl ;
			I->print();	
			cout << "==============================================================" << endl;
			cout << endl;
		}
		if ((choice == 'b') || (choice == 'B')) {
			I->set_sort_function(new BubbleSort());
        	        I->sort();
			cout << endl << "Inventory Sorted!" << endl;
		}
		if ((choice == 'c') || (choice == 'C')) {
			cout << "Enter number of item in inventory list to equip or Z to exit" << endl;
			cout << endl;	
		}
//		cin >> choice;
	}
}

void clearScreen() {
	for( int i = 0; i < 60; ++i ) {
		cout << endl;
	}
}
