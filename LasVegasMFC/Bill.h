#pragma once

class BillDeck {
private:
	int *bill;
	int top;
public:
	BillDeck();
	~BillDeck();
	void resetDeck();
	int getBill();
};
