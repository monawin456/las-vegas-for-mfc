#pragma once

class Bill {
private:
	int price;
public:
	Bill(int _price = 0);
	~Bill();
	void setPrice(int _price);
	void setPrice(Bill bill);
	int getPrice();
};

class BillDeck {
private:
	Bill *bill;
	int top;
public:
	BillDeck();
	~BillDeck();
	void resetDeck();
	Bill getBill();
};
