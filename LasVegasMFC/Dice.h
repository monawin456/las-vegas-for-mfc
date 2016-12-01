#pragma once


class Dice
{
public:
	Dice();
	~Dice();

	void RollDice();
	int GetDice();
	void setDice(int n);
	Dice& operator=(Dice& ref);


public:

private:
	int num;
};

