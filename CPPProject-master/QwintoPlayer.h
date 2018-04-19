/* 
 * University Of Ottawa
 * CSI 2372 Final Project
 * Professor : Jochen Lang
 * Group Number : 11 
 * Name : Zekun Li 8520399 Hanyang Yu 8524153
 * 
 */

#ifndef QWINTOPLAYER_H
#define QWINTOPLAYER_H
#include "RollOfDice.h"
#include "QwintoScoreSheet.h"

class QwintoPlayer : public Player
{
  public:
	QwintoPlayer(QwintoScoreSheet qs);
	void inputBeforeRoll(RollOfDice &rod);
	void inputAfterRoll(RollOfDice &rod);
	QwintoScoreSheet qtss;
	~QwintoPlayer() = default;
};

#endif /* QWINTOPLAYER_H */
