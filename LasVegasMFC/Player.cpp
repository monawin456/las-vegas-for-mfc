#include "stdafx.h"
#include "Player.h"
#include "LasVegasMFCView.h"
#include "Dice.h"

Player::Player()
{
	money = 0;
}


Player::~Player()
{
}

void Player::GetMoney(CString & Money)
{
	Money.Format(_T("Money : %d"), money);
}

void Player::AddMoney(int n)
{
	money += n;
}

void Player::GetDice(CString & k_dice)
{
	
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
		else if (dice[i].GetDice() == 6)
			num6++;
	}
	k_dice.Format(_T("1 : %d, 2 : %d, 3 : %d, 4 : %d, 5 : %d, 6 : %d"),
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

void Player::Selection(int i)
{
	switch (i) {
	case 1:
		for (int i = 0; i < num1; i++)
			num_dice--;
		break;
	case 2:
		for (int i = 0; i < num2; i++)
			num_dice--;
		break;
	case 3:
		for (int i = 0; i < num3; i++)
			num_dice--;
		break;
	case 4:
		for (int i = 0; i < num4; i++)
			num_dice--;
		break;
	case 5:
		for (int i = 0; i < num5; i++)
			num_dice--;
		break;
	case 6:
		for (int i = 0; i < num6; i++)
			num_dice--;
		break;
	}

}


