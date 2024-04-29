#pragma once
#ifndef NUMBER_NONOGRAM
#define NUMBER_NONOGRAM
#include "Line.h"
#include <string>

// класс, хранящий число и его характеристики
class NumberAndBorders
{
	typedef std::pair<int, int> myP;

	int number;		// число
	myP dia;		// (D) диапазон, в котором может теоретически находиться число
	bool isExistRD;	// флаг, показывающий, существует ли реальный диапазон
	myP realDia;	// (RD) диапазон, в котором находится только это число

public:
	// constructors, destructor, operators

	NumberAndBorders(int number, const myP& dia, const myP& realdia);

	// getters & setters

	int getNum() const;
	const myP& getD() const;
	const myP& getRD() const;
	bool getFlagExistRd() const;
	void setD(const myP& x);
	void setFlagExistRd(bool flag);
	void setRD(const myP& x);

	// functions

	void updateNumberAndBorders(const Line* const data);
	std::string toString() const;

private:
	// приближает RD до границ D, тк RD не может выходить за пределы D
	void updateRDviaD();

	// улучшает D, если в RD есть хоть одна black клетка
	void updateDviaRD(const Line* const data);
};
#endif // !NUMBER_NONOGRAM
