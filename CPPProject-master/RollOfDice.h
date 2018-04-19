/* 
 * University Of Ottawa
 * CSI 2372 Final Project
 * Professor : Jochen Lang
 * Group Number : 11 
 * Name : Zekun Li 8520399 Hanyang Yu 8524153
 * 
 */

#ifndef ROLLOFDICE_H
#define ROLLOFDICE_H
#include <iostream>
#include "Dice.h"
using namespace std;
class RollOfDice
//another head file
{

	friend ostream &operator<<(ostream &os, RollOfDice rod);

  public:
	RollOfDice();
	void add(Dice &_dice);
	Dice fetch(int posit);
	void roll();
	RollOfDice pair(Dice &diceA, Dice &diceB);
	Dice *begin();
	Dice *end();
	operator int() const;
	vector<Dice> elems;
	int num = 0;
};

#endif /* ROLLOFDICE_H */
