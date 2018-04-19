/* 
 * University Of Ottawa
 * CSI 2372 Final Project
 * Professor : Jochen Lang
 * Group Number : 11 
 * Name : Zekun Li 8520399 Hanyang Yu 8524153
 * 
 */

#include "QwintoScoreSheet.h"
#include "ScoreSheet.h"
#include "QwintoRow.h"
#include <iostream>
using namespace std;

QwintoScoreSheet::QwintoScoreSheet(string pname)
{
	name = pname;
}

ostream &operator<<(ostream &os, const QwintoScoreSheet &qtsheet)
{

	os << "Player name: " << qtsheet.name << "\t Points: "
	   << qtsheet.overallScore << endl
	   << "---------------------------------------------" << endl;
	os << qtsheet.red << endl
	   << "---------------------------------------------"
	   << endl;
	os << qtsheet.yellow << endl
	   << "---------------------------------------------" << endl;
	os << qtsheet.blue << endl
	   << "---------------------------------------------" << endl;
	os << "Failed throws: " << qtsheet.failed << endl;
	return os;
}

// first validate row, then validate column
bool QwintoScoreSheet::validate(RollOfDice rod, Colour color, int position)
{

	switch (color)
	{
	case Colour::RED:
		if (!red.validate(rod, position))
		{
			return false;
		}
		switch (position)
		{
		case 3:
			if (rod == yellow[4])
			{
				cout << "Numbers in each column must not repeat." << endl;
				return false;
			}
			break;
		case 4:
			if (rod == blue[6])
			{
				cout << "Numbers in each column must not repeat." << endl;
				return false;
			}
			break;
		default:
			if (rod == yellow[position + 1] || rod == blue[position + 2])
			{
				cout << "Numbers in each column must not repeat." << endl;
				return false;
			}
			break;
		}
		break;
	case Colour::YELLOW:
		if (!yellow.validate(rod, position))
		{
			return false;
		}
		switch (position)
		{
		case 4:
			if (rod == red[3])
			{
				cout << "Numbers in each column must not repeat." << endl;
				return false;
			}
			break;
		case 5:
			if (rod == blue[5])
			{
				cout << "Numbers in each column must not repeat." << endl;
				return false;
			}
			break;
		default:
			if (rod == red[position - 1] || rod == blue[position + 1])
			{
				cout << "Numbers in each column must not repeat." << endl;
				return false;
			}
			break;
		}

		break;
	case Colour::BLUE:
		if (!blue.validate(rod, position))
		{
			return false;
		}
		switch (position)
		{
		case 5:
			if (rod == yellow[5])
			{
				cout << "Numbers in each column must not repeat." << endl;
				return false;
			}
			break;
		case 6:
			if (rod == red[4])
			{
				cout << "Numbers in each column must not repeat." << endl;
				return false;
			}
			break;
		default:
			if (rod == red[position - 2] || rod == yellow[position - 1])
			{
				cout << "Numbers in each column must not repeat." << endl;
				return false;
			}
			break;
		}
		break;
	}
	return true;
}
//calculate total score, if the row is full, take the last element, else take the number of elements in each row
int QwintoScoreSheet::calcTotal()
{
	int total = 0;
	int counter = 0;
	for (auto a : red.scoreArray)
	{
		if (a > 0)
		{
			++counter;
		}
	}
	if (counter == 9)
	{
		total += red[9];
	}
	else
	{
		total += counter;
	}

	counter = 0;
	for (auto a : yellow.scoreArray)
	{
		if (a > 0)
		{
			++counter;
		}
	}
	if (counter == 9)
	{
		total += yellow[9];
	}
	else
	{
		total += counter;
	}

	counter = 0;
	for (auto a : blue.scoreArray)
	{
		if (a > 0)
		{
			++counter;
		}
	}
	if (counter == 9)
	{
		total += blue[9];
	}
	else
	{
		total += counter;
	}

	counter = 0;
	total -= failed * 5;
	// get the bonus entries
	if (red[2] > 0 && blue[4] > 0 && yellow[3] > 0)
	{
		total += red[2];
	}
	if (red[5] > 0 && yellow[6] > 0 && blue[7] > 0)
	{
		total += red[5];
	}
	if (yellow[7] > 0 && red[6] > 0 && blue[8] > 0)
	{
		total += yellow[7];
	}
	if (blue[3] > 0 && yellow[2] > 0 && red[1] > 0)
	{
		total += blue[3];
	}
	if (blue[9] > 0 && yellow[8] > 0 && red[7] > 0)
	{
		total += blue[9];
	}
	return total;
}
// if 2 row is full, or failed == 4, end game
bool const QwintoScoreSheet::operator!()
{
	if (failed == 4)
	{
		return true;
	}
	int fullCounter = 0;
	for (int i = 0; i < 10; ++i)
	{
		if (red[i] == 0)
		{
			break;
		}
		++fullCounter;
	}
	for (int i = 0; i < 10; ++i)
	{
		if (yellow[i] == 0)
		{
			break;
		}
		++fullCounter;
	}
	for (int i = 0; i < 10; ++i)
	{
		if (blue[i] == 0)
		{
			break;
		}
		++fullCounter;
	}
	if (fullCounter == 2)
	{
		return true;
	}
	return false;
}
