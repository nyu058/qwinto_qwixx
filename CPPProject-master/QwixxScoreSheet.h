/* 
 * University Of Ottawa
 * CSI 2372 Final Project
 * Professor : Jochen Lang
 * Group Number : 11 
 * Name : Zekun Li 8520399 Hanyang Yu 8524153
 * 
 */

#ifndef QWIXXSCORESHEET_H
#define QWIXXSCORESHEET_H
#include "QwixxRow.h"
#include "ScoreSheet.h"
#include "Colour.h"
#include <iostream>
#include <vector>
#include <list>
using namespace std;
//scoresheet for qwixx
class QwixxScoreSheet : public ScoreSheet
{

	friend ostream &operator<<(ostream &os, const QwixxScoreSheet &qxsheet);

  public:
	QwixxScoreSheet() = default;
	QwixxScoreSheet(string pname);
	~QwixxScoreSheet() = default;
	int calcTotal() override;
	bool const operator!() override;
	int lock[4] = {0, 0, 0, 0};
	QwixxRow<vector<int>, Colour::RED> red;
	QwixxRow<vector<int>, Colour::YELLOW> yellow;
	QwixxRow<list<int>, Colour::GREEN> green;
	QwixxRow<list<int>, Colour::BLUE> blue;
	int np = -1;
	bool validate(RollOfDice rod, Colour color, int position = -1) override
	{
		switch (color)
		{
		case Colour::RED:
			return red.validate(rod, np);
		case Colour::YELLOW:
			return yellow.validate(rod, np);
		case Colour::GREEN:
			return green.validate(rod, np);
		case Colour::BLUE:
			return blue.validate(rod, np);
		default:
			return false;
		}
	}
};

#endif /* QWIXXSCORESHEET_H */
