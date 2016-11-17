#pragma once
#include "Dice.h"

class Player
{
public:
	Player(); //player
	~Player();

	void GetMoney(CString&);	//���� ��
	void AddMoney(int);	//���帶�� �� �߰�
	void GetDice(CString&);		//���� ���̽� ��Ȳ

	void RoundDice();	//���帶�� ���޵Ǵ� �ֻ���
	void Rolling();		//��� �ֻ��� ������
	void Selection(int);  //ī���뿡 �ֻ��� ����
	void RemoveDice(Dice &);

public:		//Ư��
	int num_dice;

private:	//Ư��
	Dice dice[8];
	int money;
	
};

