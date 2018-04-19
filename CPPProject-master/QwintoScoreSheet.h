/* 
 * University Of Ottawa
 * CSI 2372 Final Project
 * Professor : Jochen Lang
 * Group Number : 11 
 * Name : Zekun Li 8520399 Hanyang Yu 8524153
 * 
 */

#ifndef QWINTOSCORESHEET_H
#define QWINTOSCORESHEET_H
#include "QwintoRow.h"
#include "ScoreSheet.h"
#include "Colour.h"
#include <iostream>
using namespace std;
//Score sheet for Qwinto
class QwintoScoreSheet : public ScoreSheet
{

	friend ostream &operator<<(ostream &os, const QwintoScoreSheet &qtsheet);

  public:
	QwintoScoreSheet() = default;
	QwintoScoreSheet(string pname);
	~QwintoScoreSheet() = default;
	bool validate(RollOfDice rod, Colour color, int position = -1);
	int calcTotal();
	bool const operator!();
	QwintoRow<Colour::RED> red;
	QwintoRow<Colour::YELLOW> yellow;
	QwintoRow<Colour::BLUE> blue;
};

#endif /* QWINTOSCORESHEET_H */
