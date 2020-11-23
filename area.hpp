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
				cout << endl << "Press I to view inventory, M to view map, or Z to quit the game." << endl;
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
			this->AddNorthRoom("A1", "");
			this->North->AddNorthRoom("A2", "");
			this->North->North->AddWestRoom("B1", "");
			this->North->North->AddNorthRoom("A3", "");
			this->North->North->North->AddWestRoom("C1", "");
			this->North->North->North->West->AddWestRoom("C2", "");
			this->North->North->North->West->West->AddWestRoom("C3", "");
			this->North->North->North->AddNorthRoom("A4", "");
			this->North->North->North->North->AddEastRoom("D1", "");
			this->North->North->North->North->East->AddEastRoom("D2", "");
			this->North->North->North->North->AddNorthRoom("A5", "");
			this->North->North->North->North->North->AddNorthRoom("A6", "");
			this->North->North->North->North->North->North->AddWestRoom("E1", "");
			this->North->North->North->North->North->North->AddNorthRoom("A7", "");
			this->North->North->North->North->North->North->North->AddNorthRoom("A8", "");
			this->North->North->North->North->North->North->North->North->AddWestRoom("F1", "");
			this->North->North->North->North->North->North->North->North->AddEastRoom("G1", "");
			this->North->North->North->North->North->North->North->North->East->AddEastRoom("G2", "");
			this->North->North->North->North->North->North->North->North->AddNorthRoom("A9", "");
			this->North->North->North->North->North->North->North->North->North->AddNorthRoom("A10", "");
			this->North->North->North->North->North->North->North->North->North->North->AddNorthRoom("end", "This is the last room.");
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






		void AddEastRoom(string ref, string desc) {
			this->East = new Area(0, ref, desc);
			this->East->West = this;
		}

		void AddNorthRoom(string ref, string desc) {
			this->North = new Area(0, ref, desc);
			this->North->South = this;
		}

		void AddSouthRoom(string ref, string desc) {
			this->South = new Area(0, ref, desc);
			this->South->North = this;
		}
		
		void AddWestRoom(string ref, string desc) {
			this->West = new Area(0, ref, desc);
			this->West->East = this;
		}

	};	

