#ifndef _MONSTER_
#define _MONSTER_

#include <iostream>
#include <string>
//using namespace std;

class Monster {
	public:
		int health;
		int atk;
		int def;
		std::string name;

//		Monster(string n, int h, int a, int d) {
//			name = n;
//			health = h;
//			atk = a;
//			def = d;
//		}

//		void TakeDamage(int i) {
//			health = health - i;
//		}

//		void desc() {
//			cout << "This is a " << name << "." << endl;
//			cout << "It has an attack power of " << atk << " and a defensive power of "<< def << "." << endl;
//		}

		Monster() {};
		virtual void TakeDamage(int i) = 0;
		virtual std::string desc() = 0;		
};

#endif
