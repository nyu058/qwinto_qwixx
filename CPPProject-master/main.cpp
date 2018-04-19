/* 
 * University Of Ottawa
 * CSI 2372 Final Project
 * Professor : Jochen Lang
 * Group Number : 11 
 * Name : Zekun Li 8520399 Hanyang Yu 8524153
 * 
 */

#include <iostream>
#include "QwintoScoreSheet.h"
#include "QwixxScoreSheet.h"
#include "QwintoPlayer.h"
#include "QwixxPlayer.h"
#include <vector>
#include <windows.h>

using namespace std;

int checkLock(QwixxScoreSheet &qxss)
{
	string colorlist[] = {"Red", "Yellow", "Green", "Blue"};
	int total = 0;
	int index = -1;
	bool canLock = false;
	bool last = false;

	if (!qxss.lock[0])
	{
		if ((qxss.red.scoreArray).back() > 0)
			last = true;
		for (auto a : qxss.red.scoreArray)
		{
			if (a > 0)
				total++;
			if (total == 5)
			{
				canLock = true;
				index = 0;
			}
		}
	}
	total = 0;
	if (!qxss.lock[1])
	{
		if ((qxss.yellow.scoreArray).back() > 0)
			last = true;
		for (auto a : qxss.yellow.scoreArray)
		{
			if (a > 0)
				total++;
			if (total == 5)
			{
				canLock = true;
				index = 1;
			}
		}
	}
	total = 0;
	if (!qxss.lock[2])
	{
		if ((qxss.green.scoreArray).back() > 0)
			last = true;
		for (auto a : qxss.green.scoreArray)
		{
			if (a > 0)
				total++;
			if (total == 5)
			{
				canLock = true;
				index = 2;
			}
		}
	}
	total = 0;
	if (!qxss.lock[3])
	{
		if ((qxss.blue.scoreArray).back() > 0)
			last = true;
		for (auto a : qxss.blue.scoreArray)
		{
			if (a > 0)
				total++;
			if (total == 5)
			{
				canLock = true;
				index = 3;
			}
		}
	}
	if (canLock)
	{
		cout << "You can lock your " << colorlist[index] << " row." << endl;
		cout << "Do you want to lock it? y/n" << endl;
		char check;
		bool passed = false;
		while (!passed)
		{
			cin >> check;
			if (check == 'y')
			{
				qxss.lock[index] = true;
				cout << "Locked." << endl;
				passed = true;
			}
			if (check == 'n')
			{
				passed = true;
			}
		}
	}
	if (canLock && last)
		return index;
	else
		return -1;
}

int main()
{
	bool done = false;
	while (!done)
	{
		cout << "Please choose the game version (1-Qwinto, 2-Qwixx): " << endl;
		int version;
		cin >> version;
		cout << "Please enter the number of players: " << endl;
		int count;
		cin >> count;
		if (version == 1 && count < 4 && count > 0)
		{
			cout << "Qwinto is selected." << endl;
			vector<QwintoPlayer> playerVec;
			//create players
			for (int i = 1; i <= count; ++i)
			{
				cout << "Please enter the name for player " << i << ": "
					 << endl;
				string playerName;
				cin >> playerName;
				QwintoScoreSheet *qtss = new QwintoScoreSheet(playerName);
				QwintoPlayer *player = new QwintoPlayer(*qtss);
				playerVec.push_back(*player);
			}
			bool gg = false;
			while (gg == false)
			{
				for (auto &a : playerVec)
				{ //loop over all the players, ask the active player to roll the dice
					RollOfDice rd;
					a.active = true;
					a.inputBeforeRoll(rd);
					rd.roll();
					cout << rd << endl;
					cout << a.qtss << endl;
					a.inputAfterRoll(rd);
					cout << a.qtss << endl;
					if (!a.qtss)
					{
						gg = true;
						break;
					}
					for (auto &b : playerVec)
					{ //loop over all inactive players and get their input
						if (!b.active)
						{
							cout << b.qtss;
							b.inputAfterRoll(rd);
							cout << b.qtss << endl;
							if (!b.qtss)
							{
								gg = true;
								break;
							}
						}
					}
					a.active = false;
				}
			}
			//printing score sheet and find who is the winner
			string winner;
			int high = -100;
			cout
				<< "The game has ended, calculating final score and printing score sheets..."
				<< endl;
			for (int i = 0; i <= 50; i++)
			{ // just for fun
				cout << ">";
				Sleep(100);
			}
			cout << "100%" << endl;
			for (auto a : playerVec)
			{ // loop over all player and calculate their total score, find out the player with the highest score
				a.qtss.setTotal();
				if (a.qtss.getTotal() > high)
				{
					high = a.qtss.getTotal();
					winner = a.qtss.getName();
				}

				cout << a.qtss;
			}
			cout << "The winner is: " << winner << "!" << endl;
			done = true;
		}
		else if (version == 2 && count < 4 && count > 0)
		{
			cout << "Qwixx is slected." << endl;
			vector<QwixxPlayer> playerVec;
			for (int i = 1; i <= count; ++i)
			{
				cout << "Please enter the name for player " << i << ": "
					 << endl;
				string playerName;
				cin >> playerName;
				QwixxScoreSheet *qxss = new QwixxScoreSheet(playerName);
				QwixxPlayer *player = new QwixxPlayer(*qxss);
				playerVec.push_back(*player);
			}
			int islock = -1;
			bool gg = false;
			while (gg == false)
			{
				for (auto &a : playerVec)
				{ //loop over all the players, ask the active player to roll the dice
					RollOfDice rd;
					a.active = true;
					a.inputBeforeRoll(rd);
					rd.roll();
					cout << a.qxss << endl;
					cout << "Dice: " << rd;
					cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
					a.inputAfterRoll(rd);
					islock = checkLock(a.qxss);
					if (islock != -1)
					{
						for (auto &k : playerVec)
						{
							k.qxss.lock[islock] = true;
						}
						a.qxss.lock[islock] = 2;
					}
					if (!a.qxss)
					{
						gg = true;
						break;
					}
					for (auto &b : playerVec)
					{ //loop over all inactive players and get their input
						if (!b.active)
						{
							cout << b.qxss;
							cout << "Dice: " << rd;
							cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
							b.inputAfterRoll(rd);
							islock = checkLock(a.qxss);
							if (islock != -1)
							{
								for (auto &k : playerVec)
								{
									k.qxss.lock[islock] = true;
								}
								b.qxss.lock[islock] = 2;
							}
							if (!b.qxss)
							{
								gg = true;
								break;
							}
						}
					}
					a.active = false;
				}
			}
			string winner;
			int high = -100;
			cout
				<< "The game has ended, calculating final score and printing score sheets..."
				<< endl;
			for (int i = 0; i <= 50; i++)
			{ // just for fun
				cout << ">";
				Sleep(100);
			}
			cout << "100%" << endl;
			for (auto a : playerVec)
			{ // loop over all player and calculate their total score, find out the player with the highest score
				a.qxss.setTotal();
				if (a.qxss.getTotal() > high)
				{
					high = a.qxss.getTotal();
					winner = a.qxss.getName();
				}

				cout << a.qxss;
			}
			cout << "The winner is: " << winner << "!" << endl;

			done = true;
		}
		else
		{
			cout << "Invalid Selection, please try again." << endl;
		}
	}
	system("PAUSE");
	return 0;
}
