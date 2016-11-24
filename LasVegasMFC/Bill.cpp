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
	price = n;
}

int Bill::getPrice()
{
	return price;
}

BillDeck::BillDeck()
{
	top = 100;
	for (int i = 90; i < 90; i++) {
		bill[i] = new Bill;
	}
}

BillDeck::~BillDeck()
{
	delete[]bill;
}

void BillDeck::resetDeck()
{
	int totalBill[9] = { 0 };

	int i = 0;
	while(true) {
		srand((unsigned)time(NULL));
		int tmp = rand() % 9;
		if (totalBill[tmp] != 10) {
			totalBill[tmp]++;
			bill[i] -> setPrice(tmp*10000);
		}
		if (i == 89) {
			break;
		}
	}
}

Bill *BillDeck::getBill()
{
	if (top != 0) {
		top--;
		return bill[top];
	}
	return NULL;
}
