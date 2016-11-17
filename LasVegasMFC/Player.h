#pragma once
#include "Dice.h"

class Player
{
public:
	Player();
	~Player();

	void GetMoney();	//���� ��
	void AddMoney();	//���帶�� �� �߰�
	void GetDice();		//���� ���̽� ��Ȳ

	void RoundDice();	//���帶�� ���޵Ǵ� �ֻ���
	void Rolling();		//��� �ֻ��� ������
	void GiveCasino(Dice &);  //ī���뿡 �ֻ��� ����


private:	//Ư��
	Dice dice[8];
	int money;
};

