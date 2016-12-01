#include "stdafx.h"
#include "Dice.h"


Dice::Dice()
{
	num = -1;
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

void Dice::setDice(int n)
{
	num = n;
}

Dice & Dice::operator=(Dice & ref)
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	num = ref.GetDice();
	return *this;
}
