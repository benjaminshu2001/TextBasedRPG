#include <iostream>

#include "monster.hpp"
#include "area.hpp"
#include "player.h"
//#include combatsystemclass
#include "inventory.cpp"
#include "item.h"
#include "iterator.h"
#include "visitor.h"
#include "bubble_sort.cpp"
#include "equip.h"
 
class InvIterator;

using namespace std;

char startMenu(Area* Start);
Player* createChar();
void inventoryMenu(Inventory* I, Player* p, Visitor* v);
void clearScreen();
vector<Item*> createLoot();

int main() {
	
	char input = 0;
	Area* ThisRmPntr = 0;
	Area* Begin = 0;	
	string LastRmRC = "";
	Player* Protagonist = 0;	
	Inventory* Inv = 0;
	vector<Item*> gameLoot;	


	input = startMenu(ThisRmPntr);
	if ((input == 'z') || (input == 'Z')) {
		cout << "Goodbye." << endl;
		return 0;
	}

	ThisRmPntr = ThisRmPntr->beginMap();
	LastRmRC = ThisRmPntr->Refcode();
	ThisRmPntr->referenceCode = ThisRmPntr->Refcode() + "(Here)";
	Begin = ThisRmPntr;


	Protagonist = createChar();
	Inv = new Inventory();
	gameLoot = createLoot();

	Equip* eq = new Equip("Wooden Sword");
	Equip* eq1 = new Equip(5);
	Equip* eq2 = new Equip("Leather Overalls");
	Equip* eq3 = new Equip(3);


	Weapon* it = new Weapon(eq, eq1);
	Armor* ar = new Armor(eq2, eq3);

	Armor* test = new Armor(it, ar);	
	Inv->add_element(it);
	Inv->add_element(ar);	
	
	Protagonist->equip_armor(Inv->at(1));
	Protagonist->equip_weapon(Inv->at(0));
	
    Visitor* v = new Visitor();

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
				inventoryMenu(Inv, Protagonist, v);
				cout << endl << endl;	
			}
		}
		
		else if ((input == 'm') || (input == 'M')) {
			Begin->PrintMap();
			cout << endl << endl;
		}
		
		else if ((input == 'e') || (input == 'E')) {
			Protagonist->print_stats();
        		if(Protagonist->weapon_equipped() == false) {
               			 cout << endl << "Equipped Weapon: None" << endl;
            		}
       		        else if(Protagonist->weapon_equipped() == true) {
               			 cout << endl << Protagonist->get_weapon() << endl;
           		}
            		if(Protagonist->armor_equipped() == false) {
                		cout << endl << "Equipped Armor: None" << endl;
            		}
               		else {
                		cout << endl << Protagonist->get_armor() << endl;
            		}		
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

		else if (((input == 'l') || (input == 'L')) && (ThisRmPntr->Loot != 0)) {
			if (ThisRmPntr->Enemy == 0) {		
				Inv->add_element(gameLoot.at(ThisRmPntr->Loot));
				cout << "Looted: " << gameLoot.at(ThisRmPntr->Loot)->stringify() << endl;
				ThisRmPntr->Loot = 0;
			}									
			else if (ThisRmPntr->Enemy->health <= 0) {
				Inv->add_element(gameLoot.at(ThisRmPntr->Loot));
				cout << "Looted: " << gameLoot.at(ThisRmPntr->Loot)->stringify() << endl;
				ThisRmPntr->Loot = 0;
			}										
			else {
				cout << "Cannot loot! You must first defeat the monster!" << endl;
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

void inventoryMenu(Inventory *I, Player* p, Visitor* v) {
	char choice = 0;
    int item_choice = 0;
    bool visit_counted = false;
    int inv_size = I->size();

	cout << "==============================================================" << endl;
	cout << "Here are the items that you currently have in your inventory: " << endl << endl;
        I->print();
	cout << "==============================================================" << endl;

    
	while ((choice != 'z') && (choice != 'Z')) {
		cout << "Enter A to list inventory items, B to organize by Item Type, C to equip an item,or Z to return to main screen." << endl;
		cin >> choice;
		cout << endl << endl << endl;


		if ((choice == 'a') || (choice == 'A')) {
			cout << "==============================================================" << endl;
			cout << "Here are the that items you currently have in your inventory: " << endl << endl ;
			I->print();	
            if(visit_counted == true && inv_size == I->size()) {
                cout << "Armor count: " << v->armor_count() << endl;
                cout << "Weapon count: " << v->weapon_count() << endl;
            }
            if(visit_counted == false) {
                for(int i = 0; i < I->size(); i++) {
                    I->at(i)->accept(v);
                }
                visit_counted = true;
                cout << "Armor count: " << v->armor_count() << endl;
                cout << "Weapon count: " << v->weapon_count() << endl;
            }
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
            cin >> item_choice;
            if(I->at(item_choice)->get_type() == 0) {
                p->equip_armor(I->at(item_choice));              
            }
            else if(I->at(item_choice)->get_type() == 1) {
                p->equip_weapon(I->at(item_choice));
            }
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


vector<Item*> createLoot() {
	vector<Item*> LT;
	
	Equip* dm = new Equip("Dummy");
	Equip* dm1 = new Equip(0);

	Weapon* DM = new Weapon(dm, dm1);

	Equip* A = new Equip("Shortsword");
	Equip* A1 = new Equip(6);
	Equip* B = new Equip("Longsword");
	Equip* B1 = new Equip(8);
	Equip* C = new Equip("Mace");
	Equip* C1 = new Equip(11);
	Equip* D = new Equip("Chainmail Vest");
	Equip* D1 = new Equip(5);
	Equip* E = new Equip("Scale Armor");
	Equip* E1 = new Equip(8);
	Equip* F = new Equip("Platemail Armor");
	Equip* F1 = new Equip(15);

    
	Weapon* SS = new Weapon(A, A1);
	Weapon* LS = new Weapon(B, B1);
	Weapon* MA = new Weapon(C, C1);
	Armor* CV = new Armor(D, D1);
	Armor* SA = new Armor(E, E1);
	Armor* PA = new Armor(F, F1);
	
	LT.push_back(DM);
	LT.push_back(SS);
	LT.push_back(LS);
	LT.push_back(MA);
	LT.push_back(CV);	
	LT.push_back(SA);
	LT.push_back(PA);
	
	return LT;
}
