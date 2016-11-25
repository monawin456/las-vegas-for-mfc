#pragma once

class Bill;
class Dice;

class Casino
{
private:
	int id;

	Bill *bill;

	Dice *player1Dice;
	int player1DiceNum;
	Dice *player2Dice;
	int player2DiceNum;
	Dice *player3Dice;
	int player3DiceNum;
	Dice *player4Dice;
	int player4DiceNum;
	Dice *player5Dice;
	int player5DiceNum;

public:
	Casino();
	~Casino();
	void setCasino(int _id, int playerNum, int _bill = 0);
	void setBill(Bill _bill);
	void addDice(int player, Dice dice);
};
