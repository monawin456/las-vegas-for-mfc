#include "stdafx.h"
#include "Casino.h"
#include "Bill.h"
#include "Dice.h"

Casino::Casino()
{
	bill = new Bill[5];
	billNum = 0;

	diceNum = 13;

	player1Dice = new Dice[diceNum];
	player1DiceNum = 0;
	player2Dice = new Dice[diceNum];
	player1DiceNum = 0;
	player3Dice = new Dice[diceNum];
	player1DiceNum = 0;
	player4Dice = new Dice[diceNum];
	player1DiceNum = 0;
	player5Dice = new Dice[diceNum];
	player1DiceNum = 0;
}

Casino::~Casino()
{
	delete[]bill;

	delete[]player1Dice;
	delete[]player2Dice;
	delete[]player3Dice;
	delete[]player4Dice;
	delete[]player5Dice;
}

void Casino::resetCasino()
{
	delete[]bill;

	delete[]player1Dice;
	delete[]player2Dice;
	delete[]player3Dice;
	delete[]player4Dice;
	delete[]player5Dice;

	bill = new Bill[5];
	billNum = 0;

	player1Dice = new Dice[diceNum];
	player1DiceNum = 0;
	player2Dice = new Dice[diceNum];
	player1DiceNum = 0;
	player3Dice = new Dice[diceNum];
	player1DiceNum = 0;
	player4Dice = new Dice[diceNum];
	player1DiceNum = 0;
	player5Dice = new Dice[diceNum];
	player1DiceNum = 0;
}

void Casino::addBill(Bill _bill)
{
	bill[billNum].setPrice(_bill.getPrice());
	billNum++;
}

void Casino::addDice(int player, Dice dice)
{
	if (player == 1) {
		player1Dice[player1DiceNum].setDice(dice.GetDice());
		player1DiceNum++;
	}
	else if (player == 2) {
		player2Dice[player2DiceNum].setDice(dice.GetDice());
		player2DiceNum++;
	}
	else if (player == 3) {
		player3Dice[player3DiceNum].setDice(dice.GetDice());
		player3DiceNum++;
	}
	else if (player == 4) {
		player4Dice[player4DiceNum].setDice(dice.GetDice());
		player4DiceNum++;
	}
	else if (player == 5) {
		player5Dice[player5DiceNum].setDice(dice.GetDice());
		player5DiceNum++;
	}
}
