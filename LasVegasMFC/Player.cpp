#include "stdafx.h"
#include "Player.h"
#include "Bill.h"
#include "Dice.h"
#include "Casino.h"

Player::Player(int m_id)
{
	id = m_id;
	money = 0;
	num_dice = 8;
	numberOfDice = 8;
	dice = new Dice[8];
}


Player::~Player()
{
	delete[] dice;
}
IMPLEMENT_SERIAL(Player, CObject, 1)

void Player::Serialize(CArchive & ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << money << id << name << num_dice << numberOfDice;
	}
	else
	{
		ar >> money >> id >> name >> num_dice >> numberOfDice;
	}
	for (int i = 0; i < num_dice; i++)
		dice[i].Serialize(ar);
}

int Player::GetMoney()
{
	return money;
}

void Player::AddMoney(int n)
{
	money += n;
}

void Player::GetDice(CString & k_dice)
{
	num1 = 0;
	num2 = 0;
	num3 = 0;
	num4 = 0;
	num5 = 0;
	num6 = 0;

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
	//k_dice.Format(_T("1 : %d,      2 : %d,      3 : %d,      4 : %d,      5 : %d,      6 : %d"), num1, num2, num3, num4, num5, num6);
	k_dice.Format(_T("1(%d)      2(%d)      3(%d)      4(%d)      5(%d)      6(%d)"), num1, num2, num3, num4, num5, num6);
}

void Player::RoundDice()
{
	num_dice = 8;
	delete[] dice;
	dice = new Dice[8];
}

void Player::Rolling()
{
	for (int i = 0; i < num_dice; i++)
		if(dice[i].GetDice() != 0)
		dice[i].RollDice();
}

void Player::Selection(int n, Casino *cas)
{
	for (int i = 0; i < num_dice; i++)
		if (dice[i].GetDice() == n)
		{
			cas->addDice(id, dice[i]);
			dice[i].setDice(0);
			numberOfDice--;
		}
}

int Player::GetDice(int i)
{
	return dice[i].GetDice();
}

int Player::GetDiceNum()
{
	return numberOfDice;
}

void Player::reset()
{
	delete[] dice;

	num1 = 0;
	num2 = 0;
	num3 = 0;
	num4 = 0;
	num5 = 0;
	num6 = 0;

	dice = new Dice[8];

	num_dice = 8;
	numberOfDice = 8;
}

bool Player::diceEmpty()
{
	bool result = FALSE;
	for (int i = 0; i < num_dice; i++) {
		if (dice[i].GetDice() != 0) {
			result = TRUE;
			break;
		}
	}
	return result;
}
