/* 
 * University Of Ottawa
 * CSI 2372 Final Project
 * Professor : Jochen Lang
 * Group Number : 11 
 * Name : Zekun Li 8520399 Hanyang Yu 8524153
 * 
 */

#include "RollOfDice.h"
#include <vector>

RollOfDice::RollOfDice()
{
}
// add a dice to to the deck
void RollOfDice::add(Dice &_dice)
{
	elems.push_back(_dice);
	num++;
}
// roll all dices in deck
void RollOfDice::roll()
{
	for (Dice &it : elems)
	{
		it.roll();
	}
}
//pair two dices for qwixx
RollOfDice RollOfDice::pair(Dice &diceA, Dice &diceB)
{
	RollOfDice outpt;
	outpt.add(diceA);
	outpt.add(diceB);
	return outpt;
}

Dice *RollOfDice::begin()
{
	if (num <= 0)
		throw out_of_range("Roll size out of range");
	return &elems[0];
}

Dice *RollOfDice::end()
{
	if (num <= 0)
		throw out_of_range("Roll size out of range");
	return &elems[num];
}
//conversion operator
RollOfDice::operator int() const
{
	int sum = 0;
	for (Dice a : elems)
	{
		sum += a.getFace();
	}
	return sum;
}
// insertion operator, print each dice and then print the sum of all dices
ostream &operator<<(ostream &os, RollOfDice rod)
{
	int sum = 0;
	for (Dice a : rod)
	{
		os << a << " ";
		sum += a.face;
	}
	os << "Sum: " << sum << endl;
	return os;
}
