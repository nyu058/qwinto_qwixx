/* 
 * University Of Ottawa
 * CSI 2372 Final Project
 * Professor : Jochen Lang
 * Group Number : 11 
 * Name : Zekun Li 8520399 Hanyang Yu 8524153
 * 
 */

#ifndef PLAYER_H
#define PLAYER_H
#include "RollOfDice.h"

class Player
{
  public:
	Player();
	Player(const Player &orig);
	virtual ~Player();
	virtual void inputBeforeRoll(RollOfDice &rod) = 0;
	virtual void inputAfterRoll(RollOfDice &rod) = 0;
	bool active = false;
};

#endif /* PLAYER_H */
