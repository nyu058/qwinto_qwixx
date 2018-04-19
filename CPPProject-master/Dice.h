/* 
 * University Of Ottawa
 * CSI 2372 Final Project
 * Professor : Jochen Lang
 * Group Number : 11 
 * Name : Zekun Li 8520399 Hanyang Yu 8524153
 * 
 */

#ifndef DICE_H_
#define DICE_H_
#include "Colour.h"
#include <ostream>
using namespace std;
#include <iostream>
#include "RandomDice.h"
#include "Colour.h"
#include <string>

class Dice
{

	friend ostream &operator<<(ostream &os, const Dice &d);

  public:
	static RandomDice rd;
	Dice();
	int face = 0;
	const Colour colour;
	Dice(Colour &_colour);
	void roll();
	int getFace()
	{
		return face;
	}
	Colour getColour()
	{
		return colour;
	}
};

#endif /* DICE_H_ */
