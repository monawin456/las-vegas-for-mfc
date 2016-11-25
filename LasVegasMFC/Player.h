#pragma once

class Dice;

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
	

public:		//Ư��
	int num_dice;

private:	//Ư��
	Dice* dice;
	int money;
	int num1, num2, num3, num4, num5, num6;
	
};

