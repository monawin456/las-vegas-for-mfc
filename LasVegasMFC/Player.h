#pragma once

#include "stdafx.h"
class Dice;
class Bill;
class Casino;

class Player : public CObject
{
	DECLARE_SERIAL(Player)
public:
	Player() {}
	Player(int);
	~Player();

	void Serialize(CArchive& ar);
	int GetMoney();	//현재 돈
	void AddMoney(int);	//라운드마다 돈 추가
	void GetDice(CString&);		//현재 다이스 상황

	void RoundDice();	//라운드마다 지급되는 주사위
	void Rolling();		//모든 주사위 굴리기
	void Selection(int, Casino*);  //카지노에 주사위 투자
	int GetDice(int i);

	int GetDiceNum();
	void reset();
	bool diceEmpty();
	
	CString name;
	

	int num1, num2, num3, num4, num5, num6;

private:	//특성
	Dice* dice;
	int id;
	int money;
	int num_dice;
	int numberOfDice;
	
};
