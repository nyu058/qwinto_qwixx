/* 
 * University Of Ottawa
 * CSI 2372 Final Project
 * Professor : Jochen Lang
 * Group Number : 11 
 * Name : Zekun Li 8520399 Hanyang Yu 8524153
 * 
 */

#include "Dice.h"
#include "RandomDice.h"
using namespace std;

Dice::Dice(Colour &_colour) : colour(_colour)
{
}

//roll the dice
void Dice::roll()
{

	face = rd.getDice();
}

// insertion operator for a single dice
ostream &operator<<(ostream &os, const Dice &d)
{
	string colourOut;
	switch (d.colour)
	{
	case Colour::RED:
		colourOut = "Red";
		break;
	case Colour::BLUE:
		colourOut = "Blue";
		break;
	case Colour::YELLOW:
		colourOut = "Yellow";
		break;
	case Colour::GREEN:
		colourOut = "Green";
		break;
	case Colour::WHITE:
		colourOut = "White";
		break;
	}

	os << colourOut << " " << d.face;
	return os;
}
