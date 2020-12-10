#ifndef __NORMALATTACK__
#define __NORMALATTACK__

#include <iostream>
#include <string>
#include "attack_strategy.hpp"

class NormalAttack : public AttackStrategy {
	public:
		double execute_attack(int &attack, int &monsterDef){
					//	cout << "(TEST) monsterDef inside execute_attack = " << monsterDef;
			double result;
            if(attack - monsterDef == 0) {
                return 1;
            }
            else {
                result = attack - monsterDef;
			    //	cout << "(TEST) result before return = " << result;
			    return result;
            }
		}
};

#endif
