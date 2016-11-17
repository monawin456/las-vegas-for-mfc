#pragma once
#include "Dice.h"

class Player
{
public:
	Player();
	~Player();

	void GetMoney();	//현재 돈
	void AddMoney();	//라운드마다 돈 추가
	void GetDice();		//현재 다이스 상황

	void RoundDice();	//라운드마다 지급되는 주사위
	void Rolling();		//모든 주사위 굴리기
	void GiveCasino(Dice &);  //카지노에 주사위 투자


private:	//특성
	Dice dice[8];
	int money;
};

