#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "Player.h"
#include <iostream>

class Character : public Player {
    private:
       int health;
       int attack;
       string name;
    public:
        virtual void attack() = 0;
        virtual void block() = 0;
        string getName() {
            return name;
        }


