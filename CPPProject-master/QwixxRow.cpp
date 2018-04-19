/* 
 * University Of Ottawa
 * CSI 2372 Final Project
 * Professor : Jochen Lang
 * Group Number : 11 
 * Name : Zekun Li 8520399 Hanyang Yu 8524153
 * 
 */

#include "QwixxRow.h"
#include "Colour.h"
#include <iostream>
#include <vector>
#include <list>
using namespace std;
//init row
template <>
QwixxRow<vector<int>, Colour::RED>::QwixxRow()
{
	scoreArray = vector<int>(11, 0);
}
template <>
QwixxRow<vector<int>, Colour::YELLOW>::QwixxRow()
{
	scoreArray = vector<int>(11, 0);
}
template <>
QwixxRow<list<int>, Colour::BLUE>::QwixxRow()
{
	scoreArray = list<int>(11, 0);
}
template <>
QwixxRow<list<int>, Colour::GREEN>::QwixxRow()
{
	scoreArray = list<int>(11, 0);
}
//print roll
ostream &operator<<(ostream &os, QwixxRow<vector<int>, Colour::RED> row)
{

	os << "Red      ";
	int i = 2;
	for (int a = 0; a < 11; ++a)
	{
		os << "|";
		if (row.scoreArray[a] != 0)
		{
			os << "XX";
		}
		else if (i != 0 && i < 10)
		{
			os << " " << i;
		}
		else if (i >= 10)
		{
			os << i;
		}
		++i;
	}
	os << "|";
	// if (row.scoreArray[12] != 0) {
	// 	os << "L";
	// } else {
	// 	os << "U";
	// }

	return os;
}
ostream &operator<<(ostream &os, QwixxRow<vector<int>, Colour::YELLOW> row)
{

	os << "Yellow   ";
	int i = 2;
	for (int a = 0; a < 11; ++a)
	{
		os << "|";
		if (row.scoreArray[a] != 0)
		{
			os << "XX";
		}
		else if (i != 0 && i < 10)
		{
			os << " " << i;
		}
		else if (i >= 10)
		{
			os << i;
		}
		++i;
	}
	os << "|";
	// if (row.scoreArray[12] != 0) {
	// 	os << "L";
	// } else {
	// 	os << "U";
	// }

	return os;
}
ostream &operator<<(ostream &os, QwixxRow<list<int>, Colour::GREEN> row)
{

	os << "Green    ";
	int i = 12;

	for (auto a : row.scoreArray)
	{
		os << "|";
		if (a != 0)
		{
			os << "XX";
		}
		else if (i != 0 && i < 10)
		{
			os << " " << i;
		}
		else if (i >= 10)
		{
			os << i;
		}
		if (i == 2)
		{
			break;
		}
		--i;
	}
	os << "|";
	// if (row.scoreArray.back() != 0) {
	// 	os << "L";
	// } else {
	// 	os << "U";
	// }

	return os;
}

ostream &operator<<(ostream &os, QwixxRow<list<int>, Colour::BLUE> row)
{

	os << "Blue     ";
	int i = 12;

	for (auto a : row.scoreArray)
	{
		os << "|";
		if (a != 0)
		{
			os << "XX";
		}
		else if (i != 0 && i < 10)
		{
			os << " " << i;
		}
		else if (i >= 10)
		{
			os << i;
		}
		if (i == 2)
		{
			break;
		}
		--i;
	}
	os << "|";
	// if (row.scoreArray.back() != 0) {
	// 	os << "L";
	// } else {
	// 	os << "U";
	// }

	return os;
}
