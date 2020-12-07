#include <vector>
#include <string>
//#include "Item.hpp"
#include "monster.hpp"
#include "goblin.hpp"

using namespace std;

class Area{
	public: 
		//vector<item *> loot;
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
			referenceCode = ref;
			description = "placeholder description";
		}

	
		Area(Monster* En, string ref, string desc) {
			West = 0;
			East = 0;
			South = 0;
			North = 0;
			Enemy = En;
			referenceCode = ref;
			description = desc;
		}
	

		void CurrentLocation() {
			cout << description << endl;

			if (Enemy != 0) {
				cout << "There is a " << Enemy->name << " in this room." << endl;
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
				cout << endl << "Press I to view inventory, M to view map, ";
				if (Enemy != 0) {
					cout << "Y to view monster details, X to fight monster, ";
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
			Monster* Gob = new Goblin(1, 1, 5);


			this->AddNorthRoom(Gob, "A1", "You are in a hallway.");
			this->North->AddNorthRoom(0, "A2", "You are in a hallway.");
			this->North->North->AddWestRoom(0, "B1", "");
			this->North->North->AddNorthRoom(0, "A3", "You are in a hallway.");
			this->North->North->North->AddWestRoom(0, "C1", "");
			this->North->North->North->West->AddWestRoom(0, "C2", "");
			this->North->North->North->West->West->AddWestRoom(0, "C3", "");
			this->North->North->North->AddNorthRoom(0, "A4", "You are in a hallway.");
			this->North->North->North->North->AddEastRoom(0, "D1", "");
			this->North->North->North->North->East->AddEastRoom(0, "D2", "");
			this->North->North->North->North->AddNorthRoom(0, "A5", "You are in a hallway.");
			this->North->North->North->North->North->AddNorthRoom(0, "A6", "You are in a hallway.");
			this->North->North->North->North->North->North->AddWestRoom(0, "E1", "");
			this->North->North->North->North->North->North->AddNorthRoom(0, "A7", "You are in a hallway.");
			this->North->North->North->North->North->North->North->AddNorthRoom(0, "A8", "You are in a hallway.");
			this->North->North->North->North->North->North->North->North->AddWestRoom(0, "F1", "");
			this->North->North->North->North->North->North->North->North->AddEastRoom(0, "G1", "");
			this->North->North->North->North->North->North->North->North->East->AddEastRoom(0, "G2", "");
			this->North->North->North->North->North->North->North->North->AddNorthRoom(0, "A9", "You are in a hallway.");
			this->North->North->North->North->North->North->North->North->North->AddNorthRoom(0, "A10", "");
			this->North->North->North->North->North->North->North->North->North->North->AddNorthRoom(0, "end", "This is the last room.");
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






		void AddEastRoom(Monster* m, string ref, string desc) {
			this->East = new Area(m, ref, desc);
			this->East->West = this;
		}

		void AddNorthRoom(Monster* m, string ref, string desc) {
			this->North = new Area(m, ref, desc);
			this->North->South = this;
		}

		void AddSouthRoom(Monster* m, string ref, string desc) {
			this->South = new Area(m, ref, desc);
			this->South->North = this;
		}
		
		void AddWestRoom(Monster* m, string ref, string desc) {
			this->West = new Area(m, ref, desc);
			this->West->East = this;
		}

	};	

