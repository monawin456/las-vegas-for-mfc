#include "stdafx.h"
#include "Casino.h"
#include "Bill.h"
#include "Dice.h"
#include "LasVegasMFCDoc.h"
#include "Player.h"

void Casino::setTotalPrice()
{
	totalPrice = 0;
	for (int i = 0; i < 5; i++) {
		totalPrice = totalPrice + bill[i].getPrice();
	}
}

Casino::Casino()
{
	bill = new Bill[5];
	billNum = 0;
	totalPrice = 0;

	diceNum = 13;

	player1Dice = new Dice[diceNum];
	player1DiceNum = 0;
	player2Dice = new Dice[diceNum];
	player2DiceNum = 0;
	player3Dice = new Dice[diceNum];
	player3DiceNum = 0;
	player4Dice = new Dice[diceNum];
	player4DiceNum = 0;
	player5Dice = new Dice[diceNum];
	player5DiceNum = 0;
}

Casino::~Casino()
{
	delete[]bill;

	delete[]player1Dice;
	delete[]player2Dice;
	delete[]player3Dice;
	delete[]player4Dice;
	delete[]player5Dice;
}

IMPLEMENT_SERIAL(Casino, CObject, 1)
void Casino::Serialize(CArchive & ar)
{
	CObject::Serialize(ar);


	if (ar.IsStoring())
		ar << billNum << totalPrice << diceNum <<
		player1DiceNum << player2DiceNum << player3DiceNum <<
		player4DiceNum << player5DiceNum;
	else
		ar >> billNum >> totalPrice >> diceNum >>
		player1DiceNum >> player2DiceNum >> player3DiceNum >>
		player4DiceNum >> player5DiceNum;

	player1Dice->Serialize(ar);
	player2Dice->Serialize(ar);
	player3Dice->Serialize(ar);
	player4Dice->Serialize(ar);
	player5Dice->Serialize(ar);

	for(int i = 0; i< 5; i++)
		bill[i].Serialize(ar);
	
}

void Casino::resetCasino()
{
	delete[]bill;

	delete[]player1Dice;
	delete[]player2Dice;
	delete[]player3Dice;
	delete[]player4Dice;
	delete[]player5Dice;

	bill = new Bill[5];
	billNum = 0;
	totalPrice = 0;

	player1Dice = new Dice[diceNum];
	player1DiceNum = 0;
	player2Dice = new Dice[diceNum];
	player2DiceNum = 0;
	player3Dice = new Dice[diceNum];
	player3DiceNum = 0;
	player4Dice = new Dice[diceNum];
	player4DiceNum = 0;
	player5Dice = new Dice[diceNum];
	player5DiceNum = 0;

}

void Casino::addBill(Bill _bill)
{
	bill[billNum].setPrice(_bill.getPrice());
	billNum++;
}

void Casino::addDice(int player, Dice dice)
{
	if (player == 1) {
		player1Dice[player1DiceNum].setDice(dice.GetDice());
		player1DiceNum++;
	}
	else if (player == 2) {
		player2Dice[player2DiceNum].setDice(dice.GetDice());
		player2DiceNum++;
	}
	else if (player == 3) {
		player3Dice[player3DiceNum].setDice(dice.GetDice());
		player3DiceNum++;
	}
	else if (player == 4) {
		player4Dice[player4DiceNum].setDice(dice.GetDice());
		player4DiceNum++;
	}
	else if (player == 5) {
		player5Dice[player5DiceNum].setDice(dice.GetDice());
		player5DiceNum++;
	}
}

int Casino::getTotalPrice()
{
	setTotalPrice();
	return totalPrice;
}

CString Casino::getCasinoInfo1()
{
	CString str;
	str.Format(_T("%s : %d      %s : %d"), pDoc->player1->name, player1DiceNum, pDoc->player2->name, player2DiceNum);
	return str;
}

CString Casino::getCasinoInfo2()
{
	CString str;
	str.Format(_T("%s : %d      %s : %d      %s : %d"), pDoc->player3->name, player3DiceNum, pDoc->player4->name, player4DiceNum, pDoc->player5->name, player5DiceNum);
	return str;
}

CString Casino::getCasinoInfo3()
{
	CString str;
	str.Format(_T("%d$"), totalPrice);
	return str;
}

BOOL Casino::ClosingCasino()
{
	for (int i = 8; i >= 1; i--)
	{
		if (Check(i))
		{
			if (player1DiceNum == i) {
				pDoc->player1->AddMoney(getTotalPrice());
				return TRUE;
			}
			if (player2DiceNum == i) {
				pDoc->player2->AddMoney(getTotalPrice());
				return TRUE;
			}
			if (player3DiceNum == i) {
				pDoc->player3->AddMoney(getTotalPrice());
				return TRUE;
			}
			if (player4DiceNum == i) {
				pDoc->player4->AddMoney(getTotalPrice());
				return TRUE;
			}
			if (player5DiceNum == i) {
				pDoc->player5->AddMoney(getTotalPrice());
				return TRUE;
			}
		}
		
	}
	return FALSE;
}

BOOL Casino::Check(int n)
{
	int total = 0;
	if (player1DiceNum == n)
		total++;
	if (player2DiceNum == n)
		total++;
	if (player3DiceNum == n)
		total++;
	if (player4DiceNum == n)
		total++;
	if (player5DiceNum == n)
		total++;
	
	if (total == 1)
		return TRUE;
	else
		return FALSE;
}

void Casino::printInfo(CString &strTotalPrice, CString &strDiceNum)
{
	strTotalPrice.Format(_T("Total Price: %d"), getTotalPrice());
	strDiceNum.Format(_T("player 1: %d --- player 2: %d --- player 3: %d --- player 4: %d --- player 5: %d"), player1DiceNum, player2DiceNum, player3DiceNum, player4DiceNum, player5DiceNum);
}
