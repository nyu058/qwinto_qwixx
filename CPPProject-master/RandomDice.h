/* 
 * University Of Ottawa
 * CSI 2372 Final Project
 * Professor : Jochen Lang
 * Group Number : 11 
 * Name : Zekun Li 8520399 Hanyang Yu 8524153
 * 
 */

#ifndef RANDOMDICE_H
#define RANDOMDICE_H
#include <random>
//a headfile
struct RandomDice
{

	static std::mt19937 generator;
	static std::uniform_int_distribution<unsigned> distribution;
	static int getDice();
};

#endif /* RANDOMDICE_H */
