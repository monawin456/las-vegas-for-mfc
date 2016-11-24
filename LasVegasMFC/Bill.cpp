#include "stdafx.h"
#include "Bill.h"

Bill::Bill()
{
	price = 0;
}

Bill::~Bill()
{
}

void Bill::setPrice(int n)
{
	price = n * 10000;
}

int Bill::getPrice()
{
	return price;
}

BillDeck::BillDeck()
{
	top = 100;
	bill = new Bill[100];
}

BillDeck::~BillDeck()
{
	delete[]bill;
}

void BillDeck::resetDeck()
{
	int totalBill[9] = { 0 };
	for (int i = 0; i < 100; i++) {
		srand((unsigned)time(NULL));
		int tmp = rand() % 9;
		if (totalBill[tmp] != 10) {
			totalBill[tmp]++;
			bill[i].setPrice(tmp);
		}
	}
}

int BillDeck::getBill()
{
	if (top != 0) {
		top--;
		return bill[top].getPrice();
	}
	return -1;
}
