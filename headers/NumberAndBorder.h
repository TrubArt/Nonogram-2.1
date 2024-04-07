#pragma once
#include <string>

// класс, хранящий число и его характеристики
// Dia - диапазон, в котором может теоретически находиться число
// RealDia - диапазон, в котором находится только это число
class NumberAndBorders
{
	int number;			// число
	int startDia;		// начало Dia
	int endDia;			// конец Dia
	int startRealDia;	// начало RealDia
	int endRealDia;		// конец RealDia

public:

	NumberAndBorders(int i);
	int getNumber() const;
	std::string toString() const;
};