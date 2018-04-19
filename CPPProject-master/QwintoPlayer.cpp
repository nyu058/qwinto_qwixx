/* 
 * University Of Ottawa
 * CSI 2372 Final Project
 * Professor : Jochen Lang
 * Group Number : 11 
 * Name : Zekun Li 8520399 Hanyang Yu 8524153
 * 
 */

#include "QwintoPlayer.h"
#include "RollOfDice.h"
#include "Colour.h"
#include "Dice.h"
using namespace std;

QwintoPlayer::QwintoPlayer(QwintoScoreSheet qs)
{
	qtss = qs;
}

void QwintoPlayer::inputBeforeRoll(RollOfDice &rod)
{

	cout << "Please enter the number of dice(s) to roll for player "
		 << this->qtss.getName() << ": " << endl;
	int num;
	cin >> num;
	while (cin.fail())
	{
		cout << "Please enter a number value" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Please enter the number of dice(s) to roll for player "
			 << this->qtss.getName() << ": " << endl;
		cin >> num;
	}
	if (num == 3)
	{ // if number of dice is 3, roll all dices directly
		Colour red = Colour::RED;
		Dice *r = new Dice(red);
		rod.add(*r);
		Colour yellow = Colour::YELLOW;
		Dice *y = new Dice(yellow);
		rod.add(*y);
		Colour blue = Colour::BLUE;
		Dice *b = new Dice(blue);
		rod.add(*b);
	}
	else if (num > 0 && num <= 2)
	{
		int i = 0;
		int rcount = 0;
		int ycount = 0;
		int bcount = 0;
		while (i < num)
		{ // if number of dice is less than 3, ask player which dice they want to roll
			cout << "Please select the color of dice(s) " << i + 1 << ":(r/y/b)"
				 << endl;
			Colour c;
			string ibcolour;
			cin >> ibcolour;

			if (ibcolour == "r")
			{
				c = Colour::RED;
				++rcount;
			}
			else if (ibcolour == "b")
			{
				c = Colour::BLUE;
				++bcount;
			}
			else
			{
				c = Colour::YELLOW;
				++ycount;
			}
			if (rcount > 1 || ycount > 1 || bcount > 1)
			{ // check if the color is unique
				cout << "You can't roll 2 dices with the same color! Try again."
					 << endl;
				rcount--;
				ycount--;
				bcount--;
			}
			else
			{
				Dice *d = new Dice(c);
				rod.add(*d);
				++i;
			}
		}
	}
	else
	{
		cout << "invalid number of dices" << endl;
	}
}

void QwintoPlayer::inputAfterRoll(RollOfDice &rod)
{
	bool done = false;
	while (!done)
	{
		cout << "Please select which row color to score for player "
			 << this->qtss.getName() << "," << endl
			 << "to skip scoring this number, enter 'fail':(r/y/b/fail) "
			 << endl;
		string iacolour;
		cin >> iacolour;
		if (iacolour == "fail")
		{
			this->qtss.failed++;
			break;
		}
		cout << "Please select the position to score: " << endl;
		int iscore;
		cin >> iscore;
		while (cin.fail())
		{ // check if input is a number
			cout << "Please enter a number value" << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Please select the position to score: " << endl;
			cin >> iscore;
		}
		if (iacolour == "r")
		{
			if (!qtss.score(rod, Colour::RED, iscore))
			{
				cout << "Try again?(y/n)" << endl;
				string selection;
				cin >> selection;
				if (selection == "n")
				{
					done = true;
					this->qtss.failed++;
				}
			}
			else
			{
				done = true;
			}
		}
		else if (iacolour == "b")
		{
			if (!qtss.score(rod, Colour::BLUE, iscore))
			{
				cout << "Try again?(y/n)" << endl;
				string selection;
				cin >> selection;
				if (selection == "n")
				{
					done = true;
					this->qtss.failed++;
				}
			}
			else
			{
				done = true;
			}
		}
		else if (iacolour == "y")
		{
			if (!qtss.score(rod, Colour::YELLOW, iscore))
			{
				cout << "Try again?(y/n)" << endl;
				string selection;
				cin >> selection;
				if (selection == "n")
				{
					done = true;
					this->qtss.failed++;
				}
			}
			else
			{
				done = true;
			}
			// if input is not a vaild color, loop again
		}
		else
		{
			cout << "Incorrect input.(r/y/b) :(" << endl;
		}
	}
}
