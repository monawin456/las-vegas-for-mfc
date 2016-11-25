#include "stdafx.h"
#include "Player.h"
#include "Bill.h"
#include "Dice.h"
#include "Casino.h"

Player::Player(int m_id)
{
	id = m_id;
	money = 0;
}


Player::~Player()
{
	delete dice;
}

void Player::GetMoney(CString & Money)
{
	Money.Format(_T("Money : %d"), money);
}

void Player::AddMoney(Bill * bill)
{
	money += bill -> getPrice();
}

void Player::GetDice(CString & k_dice)
{
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int num4 = 0;
	int num5 = 0;
	int num6 = 0;

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
		else if( dice[i].GetDice() == 6)
			num6++;
	}
	k_dice.Format(_T("1 : %d, 2 : %d, 3 : %d, 4 : %d, 5 : %d, 6 : %d\n"),
		num1, num2, num3, num4, num5, num6);
}

void Player::RoundDice()
{
	num_dice = 8;
	delete dice;
	dice = new Dice[8]();
}

void Player::Rolling()
{
	for (int i = 0; i < num_dice; i++)
		dice[i].RollDice();
}

void Player::Selection(int n, Casino & cas)
{
	for (int i = 0; i < num_dice; i++)
	{
		if (dice[i].GetDice() == n)
			GiveDice(i, cas);
	}
}

void Player::GiveDice(int i, Casino& cas)
{
	if (i != num_dice - 1) {
			cas.addDice(id, dice[i]);
			for (int j = i; j < num_dice - 2; j++)
				dice[j] = dice[j + 1];
		}
		else
			cas.addDice(id, dice[i]);
		num_dice--;
}
