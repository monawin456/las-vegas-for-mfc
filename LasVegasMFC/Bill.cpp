#include "stdafx.h"
#include "Bill.h"

Bill::Bill(int _price)
{
	price = _price;
}

Bill::~Bill()
{
}

void Bill::setPrice(int _price)
{
	price = _price;
}

void Bill::setPrice(Bill bill)
{
	price = bill.getPrice();
}

int Bill::getPrice()
{
	return price;
}

BillDeck::BillDeck()
{
	bill = new Bill[90];
	top = 90;
}

BillDeck::~BillDeck()
{
	delete[]bill;
}

void BillDeck::resetDeck()
{
	int totalBill[9] = { 0 };
	int i = 0;
	while (true) {
		int tmp = rand() % 9;
		if (totalBill[tmp] != 10) {
			totalBill[tmp] = totalBill[tmp] + 1;
			bill[i].setPrice((tmp + 1) * 10000);
			i++;
		}
		if (i == 90) {
			break;
		}
	}

	top = 90;
}

Bill BillDeck::getBill()
{
	if (top != 0) {
		top--;
		return bill[top];
	}
	return NULL;
}
