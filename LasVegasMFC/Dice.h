#pragma once


class Dice
{
public:
	Dice();
	~Dice();

	void RollDice();
	int GetDice();
	void setDice(int n);

public:

private:
	int num;
};

