#pragma once

class Bill : public CObject
{
	DECLARE_SERIAL(Bill)
private:
	int price;
public:
	Bill(int _price = 0);
	Bill(const Bill &bill);
	~Bill();
	void Serialize(CArchive& ar);
	void setPrice(int _price);
	void setPrice(Bill bill);
	int getPrice();
	Bill &operator=(const Bill &bill);
};

class BillDeck : public CObject
{
	DECLARE_SERIAL(BillDeck)
private:
	Bill *bill;
	int top;
public:
	BillDeck();
	~BillDeck();
	void Serialize(CArchive& ar);
	void resetDeck();
	Bill getBill();
};
