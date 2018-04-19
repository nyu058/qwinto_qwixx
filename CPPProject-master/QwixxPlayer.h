/* 
 * University Of Ottawa
 * CSI 2372 Final Project
 * Professor : Jochen Lang
 * Group Number : 11 
 * Name : Zekun Li 8520399 Hanyang Yu 8524153
 * 
 */

#ifndef QWIXXPLAYER_H
#define QWIXXPLAYER_H
#include "RollOfDice.h"
#include "QwixxScoreSheet.h"
//headfile of qwixxplayer.cpp
class QwixxPlayer : public Player
{
  public:
	QwixxPlayer(QwixxScoreSheet qs);
	void inputBeforeRoll(RollOfDice &rod);
	void inputAfterRoll(RollOfDice &rod);
	QwixxScoreSheet qxss;
};

#endif /* QWIXXPLAYER_H */
