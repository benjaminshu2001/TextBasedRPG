#ifndef __ATTACKSTRATEGY__
#define __ATTACKSTRATEGY__

#include <iostream>
#include <string>
#include <"normal_attack.hpp">
#include <"strong_attack.hpp">

using namespace std;

class AttackStrategy {
	public:
		virtual ~AttackStrategy() {}
		virtual double execute_attack(int attack, int monsterDef) = 0;

};

class AttackType {
	private:
		AttackStrategy *strategy_;		//setter to be able to change strategy at runtime
	public:
		//strategy_ is a pointer of an AttackStrategy
		//strategy is the input AttackStrategy
		AttackType(AttackStrategy *strategy = nullptr) : strategy_(strategy){}	
		~AttackType(){
			delete this->strategy_;
		}
		void setAttack(AttackStrategy *strategy){
			delete this->strategy_;
			this->strategy_ = strategy;	//replaces the AttackStrategy object
		}
		double Attack(int a, int d){
			return this->strategy_->execute_attack(a, d);
		}
};



#endif




