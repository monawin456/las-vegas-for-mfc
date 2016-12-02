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
	int GetDice(int i);
	
	CString name;
	

private:	//Ư��
	Dice* dice;
	int id;
	int money;
	int num_dice;
	

};
