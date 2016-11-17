#include "stdafx.h"
#include "Dice.h"


Dice::Dice()
{
}


Dice::~Dice()
{
}

void Dice::RollDice()
{
	num = rand() % 6 + 1;
}

int Dice::GetDice()
{
	return num;
}
