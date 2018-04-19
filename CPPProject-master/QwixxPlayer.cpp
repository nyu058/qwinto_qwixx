/* 
 * University Of Ottawa
 * CSI 2372 Final Project
 * Professor : Jochen Lang
 * Group Number : 11 
 * Name : Zekun Li 8520399 Hanyang Yu 8524153
 * 
 */

#include "QwixxPlayer.h"
#include <iostream>
#include <string>
using namespace std;

QwixxPlayer::QwixxPlayer(QwixxScoreSheet qs)
{
	qxss = qs;
}
//input before roll, adds dices to the roll of dice rod
void QwixxPlayer::inputBeforeRoll(RollOfDice &rod)
{
	if (active == false)
	{
		cout << "Wait for other player get roll....";
		return;
	}
	cout << "Your roll: " << endl;
	Colour red = Colour::RED;
	Colour yellow = Colour::YELLOW;
	Colour green = Colour::GREEN;
	Colour blue = Colour::BLUE;
	Colour white = Colour::WHITE;
	Dice *w1 = new Dice(white);
	Dice *w2 = new Dice(white);
	rod.add(*w1);
	rod.add(*w2);
	if (!qxss.lock[0])
	{
		Dice *r = new Dice(red);
		rod.add(*r);
	}
	if (!qxss.lock[1])
	{
		Dice *y = new Dice(yellow);
		rod.add(*y);
	}
	if (!qxss.lock[2])
	{
		Dice *g = new Dice(green);
		rod.add(*g);
	}
	if (!qxss.lock[3])
	{
		Dice *b = new Dice(blue);
		rod.add(*b);
	}
}
//in method inputAfterRoll, it ues this method to get a vail input. its behavior changed according to checktype
void checkInput(char &_in, QwixxScoreSheet &qxss, bool &undo, int checktype = 0)
{
	cout << "Please input a value: " << endl;
	string in;
	bool valid = false;
	while (!valid)
	{
		cin >> in;
		if (in.length() == 1)
		{
			_in = in[0];
			//check colour input
			if (checktype == 0)
			{
				switch (_in)
				{
				case 'r':
					if (!qxss.lock[0])
						valid = true;
					break;
				case 'y':
					if (!qxss.lock[1])
						valid = true;
					break;
				case 'g':
					if (!qxss.lock[2])
						valid = true;
					break;
				case 'b':
					if (!qxss.lock[3])
						valid = true;
					break;
				case 'm':
					valid = true;
					break;
				default:
					break;
				}
			}
			//check y/n input
			if (checktype == 1)
			{
				if (_in == 'y')
				{
					undo = true;
					valid = true;
				}
				if (_in == 'n')
				{
					undo = false;
					valid = true;
				}
			}
			//check a/b input
			if (checktype == 2)
			{
				if (_in == 'a')
				{
					valid = true;
				}
				if (_in == 'b')
				{
					valid = true;
				}
			}
		}
		if (valid)
			break;
		cout << "Invalid input" << endl;
	}
}
//method input after roll, run after rod get a roll
void QwixxPlayer::inputAfterRoll(RollOfDice &rod)
{
	//variables for all players
	string colorlist[] = {"Red", "Blue", "Yellow", "Green", "White"};
	Dice *d1 = nullptr;
	Dice *d2 = nullptr;
	char check;
	int face;
	for (Dice &e : rod)
	{
		if (e.getColour() == Colour::WHITE)
		{
			if (d1 == nullptr)
				d1 = &e;
			else
				d2 = &e;
		}
	}
	RollOfDice p1, p2;
	bool undo = true;
	bool pass1 = false, pass2 = false;
	Colour c;
	//part for player who rolled
	if (active)
	{
		//tip lines, it will check each row whether its locked, and number of failed
		cout << "Please select the dice which represented by colour to fill your sheet: " << endl;
		cout << "If you don't want to choose any of the dice, you can use one of your Mis-Throw chance to skip this round" << endl;
		cout << "You can choose ";
		if (!qxss.lock[0])
			cout << "r for Red; ";
		if (!qxss.lock[1])
			cout << "y for yellow; ";
		if (!qxss.lock[2])
			cout << "g for green; ";
		if (!qxss.lock[3])
			cout << "b for blue; ";
		cout << "and m for skip. " << endl;
		cout << "Currently you have " << 4 - qxss.failed << " chances to skip, note ";
		if (qxss.failed == 3)
			cout << "if you skip this time, gameover." << endl;
		else
			cout << "if you used all your chances, gameover" << endl;
		//loop to get a certain input
		while (undo)
		{
			undo = false;
			checkInput(check, qxss, undo);
			switch (check)
			{
			case 'r':
				c = Colour::RED;
				break;
			case 'y':
				c = Colour::YELLOW;
				break;
			case 'g':
				c = Colour::GREEN;
				break;
			case 'b':
				c = Colour::BLUE;
				break;
			case 'm':
				cout << "You chose to skip this round" << endl;
				cout << "You sure? You will use one of your chances to skip. y/n" << endl;
				checkInput(check, qxss, undo, 1);
				if (check == 'n')
				{
					cout << "You undid your selection" << endl;
					undo = true;
				}
				else
				{
					qxss.failed++;
					cout << endl
						 << "==========================================================================" << endl
						 << endl;
					return;
				}
				break;
			}
			//check input with row
			if (!undo)
			{
				for (Dice d : rod)
					if (d.getColour() == c)
					{
						p1 = p1.pair(*d1, d);
						p2 = p2.pair(*d2, d);
						face = d.getFace();
					}
				cout << "You chose " << colorlist[(int)c] << " , its face is " << face << endl;
				cout << "Sum of two sets with white dice is " << endl
					 << p1 << p2 << endl;
				//add result to pass1 pass2
				pass1 = qxss.validate(p1, c);
				pass2 = qxss.validate(p2, c);
				//check which one can add into the row, if neither can put inside it will back to while loop
				if (pass1 & pass2)
					cout << "You can add either one of two set to your " << colorlist[(int)c] << " row." << endl;
				else if (pass1)
					cout << "Now you can add only one set to your " << colorlist[(int)c] << " row." << endl
						 << p1;
				else if (pass2)
					cout << "Now you can add only one set to your " << colorlist[(int)c] << " row." << endl
						 << p2;
				else
				{
					cout << "But you can't add any one of the set to your " << colorlist[(int)c] << " row." << endl
						 << "Please reselect a colour" << endl;
					undo = true;
					continue;
				}
				cout << "You sure? y/n" << endl;
				checkInput(check, qxss, undo, 1);
				undo = !undo;
				if (undo)
					cout << "You undid your selection" << endl;
			}
		}
		//add valid set to row
		//2 sets can have two,one or zero set available. As 0 set will restart while loop, following code add 2 or 1 set
		if (!(pass1 & pass2))
		{
			//one set
			if (pass2)
			{
				qxss.score(p2, c);
				cout << p2 << "This set has added to your " << colorlist[(int)c] << " row." << endl;
			}
			if (pass1)
			{
				qxss.score(p1, c);
				cout << p1 << "This set has added to your " << colorlist[(int)c] << " row." << endl;
			}
		}
		//two sets
		else
		{
			cout << "Please choose the one you like to add to your sheet: " << endl;
			cout << p1 << "is represented by a " << endl
				 << p2 << "is represented by b." << endl;
			checkInput(check, qxss, undo, 2);
			cout << "You chose ";
			if (check == 'a')
			{
				qxss.score(p1, c);
				cout << p1 << endl;
			}
			else
			{
				qxss.score(p2, c);
				cout << p2 << endl;
			}
		}
		cout << endl
			 << "==========================================================================" << endl
			 << endl;
	}
	//part for player who didnt rolled
	else
	{
		check = 'f';
		p1 = p1.pair(*d1, *d2);
		cout << "Your action" << endl;
		int publicNum = p1;
		cout << "Public number: " << publicNum << endl;
		undo = true;
		cout << "Please choose the colour where you want to put the public number" << endl;
		cout << "You can choose ";
		if (!qxss.lock[0])
			cout << "r for Red; ";
		if (!qxss.lock[1])
			cout << "y for yellow; ";
		if (!qxss.lock[2])
			cout << "g for green; ";
		if (!qxss.lock[3])
			cout << "b for blue; ";
		cout << "and m to skip. " << endl;
		//similar to player who rolled
		while (undo)
		{
			undo = false;
			checkInput(check, qxss, undo);
			switch (check)
			{
			case 'r':
				c = Colour::RED;
				break;
			case 'y':
				c = Colour::YELLOW;
				break;
			case 'g':
				c = Colour::GREEN;
				break;
			case 'b':
				c = Colour::BLUE;
				break;
			case 'm':
				cout << "You chose to skip this round" << endl;
				cout << "You sure? y/n" << endl;
				checkInput(check, qxss, undo, 1);
				if (check == 'y')
				{
					cout << endl
						 << "==========================================================================" << endl
						 << endl;
					return;
				}
				else
				{
					undo = true;
					break;
				}
			}
			if (!undo)
			{
				if (qxss.validate(p1, c))
				{
					cout << "Public number: " << publicNum << " will add to your " << colorlist[(int)c] << " row" << endl;
					cout << "You Sure? y/n" << endl;
					checkInput(check, qxss, undo, 1);
					if (check == 'y')
					{
						Dice *nulldice = new Dice(c);
						p1.add(*nulldice);
						if (qxss.validate(p1, c))
						{
							qxss.score(p1, c);
							cout << "Number added." << endl;
							cout << endl
								 << "==========================================================================" << endl
								 << endl;
							return;
						}
						else
						{
							cout << "Oops, you can't place the number there" << endl;
							undo = true;
						}
					}
					else
					{
						undo = true;
						cout << "You undid your action" << endl;
					}
				}
			}
		}
	}
}
