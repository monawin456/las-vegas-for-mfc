#pragma once

#include "stdafx.h"
class Dice;
class Bill;

class Player
{
public:
	Player();
	~Player();

	void GetMoney(CString&);	//���� ��
	void AddMoney(Bill*);	//���帶�� �� �߰�
	void GetDice(CString&);		//���� ���̽� ��Ȳ

	void RoundDice();	//���帶�� ���޵Ǵ� �ֻ���
	void Rolling();		//��� �ֻ��� ������
	void Selection(int);  //ī���뿡 �ֻ��� ����
	void RemoveDice(Dice &);

private:	//Ư��
	Dice* dice;
	int money;
	int num_dice;
};
