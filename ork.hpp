#ifndef __ORK__
#define __ORK__

class Ork : public Monster {
	public:
		Ork(int a, int d, int h){
			name = "Ork";
			atk = a;
			def = d;
			health = h;
		}

		void TakeDamage(int i) {
			health -= i;
		}

		string desc() {
			string description = "This is an ork. It has an attack power of ";
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
