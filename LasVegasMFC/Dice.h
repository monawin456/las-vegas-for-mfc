#pragma once
#include <iostream>

class Dice
{
public:
	Dice();
	~Dice();

	void RollDice();
	int GetDice();

public:

private:
	int num;
};

