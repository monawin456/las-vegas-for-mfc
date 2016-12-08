#pragma once

class Bill;
class Dice;
class CLasVegasMFCDoc;

class Casino
{
private:
	Bill *bill;
	int billNum;
	int totalPrice;

	int diceNum;

	Dice *player1Dice;
	int player1DiceNum;
	Dice *player2Dice;
	int player2DiceNum;
	Dice *player3Dice;
	int player3DiceNum;
	Dice *player4Dice;
	int player4DiceNum;
	Dice *player5Dice;
	int player5DiceNum;

private:
	void setTotalPrice();

public:
	CLasVegasMFCDoc *pDoc;

	Casino();
	~Casino();
	void resetCasino();
	void addBill(Bill _bill);
	void addDice(int player, Dice dice);
	int getTotalPrice();
	CString getCasinoInfo1();
	CString getCasinoInfo2();
	CString getCasinoInfo3();

	void printInfo(CString &strTotalPrice, CString &strDiceNum);
};
