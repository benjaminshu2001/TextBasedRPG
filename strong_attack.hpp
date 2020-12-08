#ifndef __STRONGATTACK__
#define __STRONGATTACK__

#include <iostream>
#include <string>

using namespace std;

class StrongAttack {
	public:
		double execute_attack(int attack, int monsterDef){
			double STRONG_MULTIPLIER = 2;
			double result;
			result = (attack * STRONG_MULTIPLIER) - monsterDef;
			return result;
		}
};

#endif