#include <vector>
#include <string>
//#include "Item.hpp"
#include "monster.hpp"

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

	
		Area(Area *w, Area *e, Area *s, Area *n, Monster* En, string ref, string desc) {
			West = w;
			East = e;
			South = s;
			North = n;
			Enemy = En;
			referenceCode = ref;
			description = desc;
		}
	

		void CurrentLocation() {
			cout << description << endl << endl;
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
				cout << endl << "Press I to view inventory or Z to quit the game." << endl;
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
			this->AddNorthRoom("A1");
			this->North->AddNorthRoom("A2");
			this->North->North->AddWestRoom("B1");
			this->North->North->AddNorthRoom("A3");
			this->North->North->North->AddWestRoom("C1");
			this->North->North->North->West->AddWestRoom("C2");
			this->North->North->North->West->West->AddSouthRoom("C3");
			this->North->North->North->AddNorthRoom("A4");
			this->North->North->North->North->AddEastRoom("D1");
			this->North->North->North->North->East->AddEastRoom("D2");
			this->North->North->North->North->AddNorthRoom("A5");
			this->North->North->North->North->North->AddNorthRoom("A6");
			this->North->North->North->North->North->North->AddWestRoom("E1");
			this->North->North->North->North->North->North->AddNorthRoom("A7");
			this->North->North->North->North->North->North->North->AddNorthRoom("A8");
			this->North->North->North->North->North->North->North->North->AddWestRoom("F1");
			this->North->North->North->North->North->North->North->North->AddEastRoom("G1");
			this->North->North->North->North->North->North->North->North->East->AddEastRoom("G2");
			this->North->North->North->North->North->North->North->North->AddNorthRoom("A9");
			this->North->North->North->North->North->North->North->North->North->AddNorthRoom("A10");
			this->North->North->North->North->North->North->North->North->North->North->AddEastRoom("end");
		}
		void AddEastRoom(string ref) {
			this->East = new Area(ref);
			this->East->West = this;
		}

		void AddNorthRoom(string ref) {
			this->North = new Area(ref);
			this->North->South = this;
		}

		void AddSouthRoom(string ref) {
			this->South = new Area(ref);
			this->South->North = this;
		}
		
		void AddWestRoom(string ref) {
			this->West = new Area(ref);
			this->West->East = this;
		}

	};	

