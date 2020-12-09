#include <vector>
#include <string>
#include "monster.hpp"
#include "goblin.hpp"
#include "ork.hpp"
#include "minotaur.hpp"

using namespace std;


class Area{
	public: 
		int Loot;
		Area *West;
		Area *East;
		Area *South;
		Area *North;
		Monster* Enemy;
		string referenceCode;
		string description;
		
		
		Area(string ref) {
			West = 0;
			East = 0;
			South = 0;
			North = 0;
			Enemy = 0;
			Loot = 0;
			referenceCode = ref;
			description = "placeholder description";
		}

							
		Area(Monster* En, string ref, string desc, int l) {
			West = 0;
			East = 0;
			South = 0;
			North = 0;
			Enemy = En;
			Loot = l;
			referenceCode = ref;
			description = desc;
		}
	

		void CurrentLocation() {
			cout << description << endl;

			if ((Enemy != 0) && (Enemy->health > 0)) {
				cout << "There is a " << Enemy->name << " in this room." << endl;
			}
			if (Loot != 0) {
				cout << "There is loot in this room!" << endl;
			}
			cout << endl;

			if (referenceCode != "end") {			
				cout << "You may move:  ";
				if (West != 0) {
					cout << "West[A] ";
				}
				if (East != 0) {
					cout << "East[D] ";
				}
				if (North != 0) {
					cout << "North[W] ";
	 			}
				if (South != 0) {
					cout << "South[S] ";
				}
				cout << endl << "Enter I to view inventory, M to view map, E to examine self, ";
				
				if ((Enemy != 0) && (Enemy->health > 0)) {
					cout << "Y to view monster details, X to fight monster, ";
				}
			
				if (Loot != 0) {
					cout << "L to loot, ";
				}

				cout <<	"or Z to quit the game." << endl;
			} 
		}


		bool MoveChecker(int moveVal) {
			if (moveVal == 1 && West == 0) {
				return false;
			}
			if (moveVal == 2 && East == 0) {
				return false;
			}
			if (moveVal == 3 && South == 0) {
				return false;
			}
			if (moveVal == 4 && North == 0) {
				return false;
			}
			return true;
		}
		
		string Refcode() {
			 return referenceCode;
		}

		void fillMap() {
			Monster* GobA = new Goblin(1, 1, 5);
			Monster* GobB = new Goblin(3, 4, 10);
			Monster* GobC = new Goblin(5, 5, 15);
			Monster* OrkA = new Ork(8, 10, 20);
			Monster* Mina = new Minotaur(15, 15, 30);
		

			this->AddNorthRoom(GobA, "A1", "You are in a hallway.", 0);
			this->North->AddNorthRoom(0, "A2", "You are in a hallway.", 1);
			this->North->North->AddWestRoom(GobB, "B1", "", 4);
			this->North->North->AddNorthRoom(0, "A3", "You are in a hallway.", 0);
			this->North->North->North->AddWestRoom(0, "C1", "", 0);
			this->North->North->North->West->AddWestRoom(0, "C2", "", 0);
			this->North->North->North->West->West->AddWestRoom(0, "C3", "", 0);		
			this->North->North->North->AddNorthRoom(GobC, "A4", "You are in a hallway.", 0);
			this->North->North->North->North->AddEastRoom(0, "D1", "", 0);
			this->North->North->North->North->East->AddEastRoom(0, "D2", "", 5);
			this->North->North->North->North->AddNorthRoom(0, "A5", "You are in a hallway.", 0);
			this->North->North->North->North->North->AddNorthRoom(0, "A6", "You are in a hallway.", 0);
			this->North->North->North->North->North->North->AddWestRoom(GobB, "E1", "", 2);
			this->North->North->North->North->North->North->AddNorthRoom(0, "A7", "You are in a hallway.", 0);
			this->North->North->North->North->North->North->North->AddNorthRoom(0, "A8", "You are in a hallway.", 0);
			this->North->North->North->North->North->North->North->North->AddWestRoom(GobC, "F1", "", 3);
			this->North->North->North->North->North->North->North->North->AddEastRoom(0, "G1", "", 0);
			this->North->North->North->North->North->North->North->North->East->AddEastRoom(0, "G2", "", 0);
			this->North->North->North->North->North->North->North->North->AddNorthRoom(OrkA, "A9", "You are in a hallway.", 6);
			this->North->North->North->North->North->North->North->North->North->AddNorthRoom(Mina, "A10", "", 0);
			this->North->North->North->North->North->North->North->North->North->North->AddNorthRoom(0, "end", "This is the last room.", 0);
		}
												
		Area* beginMap() {
			cout << "Beginning Map Construction..." << endl << endl;																	
			Area* Begin = new Area(0, "Start", "You are standing in fron of the entrance into the dungeon.", 0);
			Begin->fillMap();														
												
			cout << "Map Construction Finished." << endl << endl << endl;
			return Begin;
		}

		void PrintMap() {
			if(this->North != 0) {
				this->North->PrintMap();
			}
			
			
			int wOffset = 5;
			Area* Printer = this;
			while(Printer->West != 0) {
				Printer = Printer->West;
				--wOffset;
			}
			
//			if((Printer->East != this) && (Printer != this)) {
//				cout << Printer->Refcode() << " - ";
//				--wOffset;
//			}			

			for(int i = 0; i < wOffset; ++i) {
				cout << "     ";
			}
		
			while(Printer->East != 0) {
				cout << Printer->Refcode() << " - ";
				Printer = Printer->East;
			}

			cout << Printer->Refcode() << endl;	
		}





										
		void AddEastRoom(Monster* m, string ref, string desc, int l) {
			this->East = new Area(m, ref, desc, l);
			this->East->West = this;
		}
																
		void AddNorthRoom(Monster* m, string ref, string desc, int l) {
			this->North = new Area(m, ref, desc, l);
			this->North->South = this;
		}
																	
		void AddSouthRoom(Monster* m, string ref, string desc, int l) {
			this->South = new Area(m, ref, desc, l);
			this->South->North = this;		
		}					
											
		void AddWestRoom(Monster* m, string ref, string desc, int l) {
			this->West = new Area(m, ref, desc, l);
			this->West->East = this;
		}

	};	

