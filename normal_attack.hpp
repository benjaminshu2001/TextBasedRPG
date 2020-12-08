#ifndef __NORMALATTACK__
#define __NORMALATTACK__

#include <iostream>
#include <string>

using namespace std;

class NormalAttack {
	public:
		double execute_attack(int attack, int monsterDef){
			double result;
			result = attack - monsterDef;
			return result;
		}
};

#endif