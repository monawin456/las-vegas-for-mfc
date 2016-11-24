#pragma once

class Bill
{
private:
	int price;
public:
	Bill();
	~Bill();
	void setPrice(int n);
	int getPrice();
};

class BillDeck {
private:
	Bill **bill;
	int top;
public:
	BillDeck();
	~BillDeck();
	void resetDeck();
	Bill *getBill();
};
