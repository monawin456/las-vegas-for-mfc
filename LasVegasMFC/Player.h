#pragma once

#include "stdafx.h"
class Dice;
class Bill;

class Player
{
public:
	Player();
	~Player();

	void GetMoney(CString&);	//현재 돈
	void AddMoney(Bill*);	//라운드마다 돈 추가
	void GetDice(CString&);		//현재 다이스 상황

	void RoundDice();	//라운드마다 지급되는 주사위
	void Rolling();		//모든 주사위 굴리기
	void Selection(int);  //카지노에 주사위 투자
	void RemoveDice(Dice &);

public:		//특성
	int num_dice;

private:	//특성
	Dice* dice;
	int money;
	
};

