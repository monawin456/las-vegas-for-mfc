#include "stdafx.h"
#include "Player.h"
#include "LasVegasMFCView.h"
#include "Bill.h"
#include "Dice.h"

Player::Player()
{
	money = 10000;
}


Player::~Player()
{
}

void Player::GetMoney(CString & Money)
{
	Money.Format(_T("Money : %d"), money);
}

void Player::AddMoney(Bill &bill)
{
	
}

void Player::GetDice(CString & k_dice)
{
	int num1, num2, num3, num4, num5, num6;
	num1 = num2 = num3 = num4 = num5 = num6 = 0;
	for (int i = 0; i < num_dice; i++)
	{
		if (dice[i].GetDice() == 1)
			num1++;
		else if (dice[i].GetDice() == 2)
			num2++;
		else if (dice[i].GetDice() == 3)
			num3++;
		else if (dice[i].GetDice() == 4)
			num4++;
		else if (dice[i].GetDice() == 5)
			num5++;
		else
			num6++;
	}
	k_dice.Format(_T("1 : %d, 2 : %d, 3 : %d, 4 : %d, 5 : %d, 6 : %d\n"),
		num1, num2, num3, num4, num5, num6);
}

void Player::RoundDice()
{
	num_dice = 8;
	dice = new Dice[8]();
}

void Player::Rolling()
{
	for (int i = 0; i < num_dice; i++)
		dice[i].RollDice();
}

void Player::Selection(int)
{
}

void Player::RemoveDice(Dice &)
{
}
