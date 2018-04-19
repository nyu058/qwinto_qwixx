/* 
 * University Of Ottawa
 * CSI 2372 Final Project
 * Professor : Jochen Lang
 * Group Number : 11 
 * Name : Zekun Li 8520399 Hanyang Yu 8524153
 * 
 */

#ifndef QWIXXROW_H
#define QWIXXROW_H
#include "RollOfDice.h"
#include "Colour.h"
#include <iostream>
using namespace std;
//row of qwixx score sheet
template <class T, Colour C>
class QwixxRow
{
	friend ostream &operator<<(ostream &os, QwixxRow<T, C> row);

  public:
	QwixxRow();
	QwixxRow<T, C> operator+=(RollOfDice rod);
	bool validate(RollOfDice rod, int &position);
	T scoreArray;
};
template <class T, Colour C>
//Check whether we can put the rod at the position
bool QwixxRow<T, C>::validate(RollOfDice rod, int &position)
{
	int counter = 0;
	if (C == Colour::RED || C == Colour::YELLOW)
		position = rod - 2;
	else
		position = 12 - rod;
	for (auto a : scoreArray)
	{
		if (position > counter)
			++counter;
		else if (a > 0)
			return false;
	}
	return true;
};
template <class T, Colour C>
QwixxRow<T, C> QwixxRow<T, C>::operator+=(RollOfDice rd)
{
	int position, counter = 0;
	validate(rd, position);
	for (auto &a : scoreArray)
	{
		if (position == counter)
		{
			a = rd;
			break;
		}
		++counter;
	}
	return *this;
};

#endif /* QWIXXROW_H */
