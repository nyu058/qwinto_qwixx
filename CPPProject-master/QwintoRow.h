/* 
 * University Of Ottawa
 * CSI 2372 Final Project
 * Professor : Jochen Lang
 * Group Number : 11 
 * Name : Zekun Li 8520399 Hanyang Yu 8524153
 * 
 */

#ifndef QWINTOROW_H
#define QWINTOROW_H
#include "Dice.h"
#include "Colour.h"
#include "RollOfDice.h"
#include <iostream>
#include <array>
using namespace std;

template <Colour C>
class QwintoRow
{

	friend ostream &operator<<(ostream &os, QwintoRow<C> row);

  public:
	bool validate(RollOfDice rd, int pos);
	int &operator[](int i)
	{
		return scoreArray[i - 1];
	}

	int scoreArray[10] = {};
};
template <Colour C>
bool QwintoRow<C>::validate(RollOfDice rd, int pos)
{ // validate the row
	// check if roll of dice contains the same colored dice as the row
	bool cCheck = false;
	for (auto a : rd)
	{
		if (a.colour == C)
		{
			cCheck = true;
		}
	}
	if (!cCheck)
	{
		cout << "Row selected does not match the color of dices rolled."
			 << endl;
		return false;
	}

	if (pos < 0 || pos > 9)
	{
		cout << "Index out of range." << endl;
		return false;
	}
	// check if the position is empty
	if (scoreArray[pos - 1] != 0)
	{
		cout << "This position is already occupied." << endl;
		return false;
	}
	int i;
	// check the number on the left is smaller
	for (i = pos - 1; i > -1; --i)
	{
		if (scoreArray[i] >= rd && scoreArray[i] > 0)
		{
			cout << "the number on the left must be smaller than this" << endl;
			return false;
		}
	}
	// check the number on the right is greater
	for (i = pos - 1; i < 10; ++i)
	{

		if (scoreArray[i] <= rd && scoreArray[i] > 0)
		{
			cout << "the number on the right must be greater than this" << endl;
			return false;
		}
	}
	return true;
}

#endif /* QWINTOROW_H */
