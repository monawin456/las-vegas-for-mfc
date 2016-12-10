#pragma once


class Dice : public CObject
{
	DECLARE_SERIAL(Dice)
public:
	Dice();
	Dice(const Dice &dice);
	~Dice();

	void Serialize(CArchive& ar);
	void RollDice();
	int GetDice();
	void setDice(int n);
	Dice& operator=(Dice& ref);


public:

private:
	int num;
};

