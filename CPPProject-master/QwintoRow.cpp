/* 
 * University Of Ottawa
 * CSI 2372 Final Project
 * Professor : Jochen Lang
 * Group Number : 11 
 * Name : Zekun Li 8520399 Hanyang Yu 8524153
 * 
 */

#include "QwintoRow.h"
#include "Colour.h"
#include "RollOfDice.h"
#include <iostream>

//insertion operator for red row
ostream &operator<<(ostream &os, QwintoRow<Colour::RED> row)
{
	os << "Red           ";
	for (int i = 0; i < 10; ++i)
	{
		switch (i)
		{
		case 1:
			os << "%";
			break;
		case 2:
			os << "%";
			break;
		case 3:
			os << "|XX|";
			break;
		case 4:
			os << "%";
			break;
		case 5:
			os << "%";
			break;
		default:
			os << "|";
			break;
		}
		if (i != 9)
		{
			if (row.scoreArray[i] != 0 && row.scoreArray[i] < 10)
			{
				os << " " << row.scoreArray[i];
			}
			else if (row.scoreArray[i] >= 10)
			{
				os << row.scoreArray[i];
			}
			else
			{
				os << "  ";
			}
		}
	}
	return os;
}
//insertion operator for yellow row
ostream &operator<<(ostream &os, QwintoRow<Colour::YELLOW> row)
{
	os << "Yellow     ";
	for (int i = 0; i < 10; ++i)
	{
		switch (i)
		{
		case 5:
			os << "|XX|";
			break;
		case 6:
			os << "%";
			break;
		case 7:
			os << "%";
			break;
		default:
			os << "|";
			break;
		}
		if (i != 9)
		{
			if (row.scoreArray[i] != 0 && row.scoreArray[i] < 10)
			{
				os << " " << row.scoreArray[i];
			}
			else if (row.scoreArray[i] >= 10)
			{
				os << row.scoreArray[i];
			}
			else
			{
				os << "  ";
			}
		}
	}

	return os;
}
//insertion operator for blue row
ostream &operator<<(ostream &os, QwintoRow<Colour::BLUE> row)
{
	os << "Blue    ";
	for (int i = 0; i < 10; ++i)
	{
		switch (i)
		{
		case 2:
			os << "%";
			break;
		case 3:
			os << "%";
			break;
		case 4:
			os << "|XX|";
			break;
		case 8:
			os << "%";
			break;
		case 9:
			os << "%";
			break;
		default:
			os << "|";
			break;
		}
		if (i != 9)
		{
			if (row.scoreArray[i] != 0 && row.scoreArray[i] < 10)
			{
				os << " " << row.scoreArray[i];
			}
			else if (row.scoreArray[i] >= 10)
			{
				os << row.scoreArray[i];
			}
			else
			{
				os << "  ";
			}
		}
	}

	return os;
}
