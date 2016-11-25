#include "stdafx.h"
#include "Bill.h"

BillDeck::BillDeck()
{
	top = 90;
	bill = new int[90];
}

BillDeck::~BillDeck()
{
	delete[]bill;
}

void BillDeck::resetDeck()
{
	top = 90;

	int totalBill[9] = { 0 };

	int i = 0;
	while (true) {
		int tmp = rand() % 9;
		if (totalBill[tmp] != 10) {
			totalBill[tmp] = totalBill[tmp] + 1;
			bill[i] = (tmp + 1) * 10000;
			i++;
		}
		if (i == 90) {
			break;
		}
	}
}

int BillDeck::getBill()
{
	if (top != 0) {
		top--;
		return bill[top];
	}
	return -1;
}
