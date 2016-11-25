#pragma once

#include "stdafx.h"
class Dice;
class Bill;
class Casino;

class Player
{
public:
	Player(int);
	~Player();

	void GetMoney(CString&);	//���� ��
	void AddMoney(Bill*);	//���帶�� �� �߰�
	void GetDice(CString&);		//���� ���̽� ��Ȳ

	void RoundDice();	//���帶�� ���޵Ǵ� �ֻ���
	void Rolling();		//��� �ֻ��� ������
	void Selection(int, Casino&);  //ī���뿡 �ֻ��� ����
	void GiveDice(int, Casino&);

private:	//Ư��
	Dice* dice;
	int id;
	int money;
	int num_dice;
	int num1, num2, num3, num4, num5, num6;

};
