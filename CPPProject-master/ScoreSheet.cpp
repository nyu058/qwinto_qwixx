/* 
 * University Of Ottawa
 * CSI 2372 Final Project
 * Professor : Jochen Lang
 * Group Number : 11 
 * Name : Zekun Li 8520399 Hanyang Yu 8524153
 * 
 */

#include "ScoreSheet.h"
#include <iostream>
#include <stdio.h>
#include "QwintoScoreSheet.h"
#include "QwixxScoreSheet.h"
#include <typeinfo>
using namespace std;

ostream &operator<<(ostream &out, const ScoreSheet &sheet)
{
	return out;
}
ScoreSheet::ScoreSheet()
{
}
ScoreSheet::ScoreSheet(string pname)
{
	name = pname;
}

// first validate if the score is valid, then score the dice accoring to input
bool ScoreSheet::score(RollOfDice rod, Colour color, int position)
{

	if (!validate(rod, color, position))
	{

		return false;
	}
	else
	{
		//check this type, cast to corresponding and add score to score sheet
		if (typeid(*this) == typeid(QwintoScoreSheet))
		{
			QwintoScoreSheet *qts = dynamic_cast<QwintoScoreSheet *>(this);
			switch (color)
			{
			case Colour::RED:
				qts->red[position] = rod;
				return true;
				break;
			case Colour::BLUE:
				qts->blue[position] = rod;
				return true;
				break;
			case Colour::YELLOW:
				qts->yellow[position] = rod;
				return true;
				break;
			}
		}
		else
		{
			QwixxScoreSheet *qxs = dynamic_cast<QwixxScoreSheet *>(this);
			for (Dice &a : rod)
			{
				if (a.getColour() != Colour::WHITE)
				{
					color = a.getColour();
				}
				switch (color)
				{
				case Colour::RED:
					qxs->red += rod;
					return true;
					break;
				case Colour::YELLOW:
					qxs->yellow += rod;
					return true;
					break;
				case Colour::GREEN:
					qxs->green += rod;
					return true;
					break;
				case Colour::BLUE:
					qxs->blue += rod;
					return true;
					break;
				case Colour::WHITE:
					return true;
					break;
				}
			}
		}
	}
}

void ScoreSheet::setTotal()
{

	overallScore = calcTotal();
}
