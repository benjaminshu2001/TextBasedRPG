#ifndef __GOB__
#define __GOB__

#include "monster.hpp"
#include <iostream>
#include <string>
using namespace std;

class Goblin : public Monster {
	public:
		Goblin(int a, int d, int h) {
			name = "Goblin";
			atk = a;
			health = h;
			def = d;
		}


		void TakeDamage(int i) {
			health -= i;	
		}

		string desc() {
			string description = "This is a goblin. It has an attack power of ";
			string attack = to_string(this->atk);
			string defend = to_string(def);
			string hp = to_string(health); 	
			description += attack;
			description += ", a defensive value of ";			
			description += defend;
			description += ", and ";
			description += hp;
			description += " health points.";
			return description;
		}


};

#endif
