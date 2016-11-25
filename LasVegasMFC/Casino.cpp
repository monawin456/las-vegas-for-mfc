#include "stdafx.h"
#include "Casino.h"
#include "Dice.h"

Casino::Casino()
{
	id = -1;
	//player = NULL;
	bill = 0;
}

Casino::~Casino()
{
	delete[]player1Dice;
	delete[]player2Dice;
	delete[]player3Dice;
	delete[]player4Dice;
	delete[]player5Dice;
}

void Casino::setCasino(int _id, int playerNum, int _bill)
{
	id = _id;

	//player = new int[playerNum];
	for (int i = 0; i < playerNum; i++) {
		//player[i] = 0;
	}

	//bill = _bill;
}

void Casino::addDice(int player, Dice dice)
{
	//player1Dice[0].set(dice.get());
}
