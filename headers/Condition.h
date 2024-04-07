#pragma once
#include "Line.h"
#include <vector>

class Condition
{
	struct NumberAndBorders
	{
		int number;			// число
		int startDia;		// Dia - диапазон, в котором может теоретически находиться число
		int endDia;			// 
		int startRealDia;	// RealDia - диапазон, в котором находится только это число
		int endRealDia;		// 
	};

	// неизменяемые в процессе решения величины

	int CNField;			// conditionNecessaryField - '1'
	int CUField;			// conditionUnnecessaryField - '0'

	// изменяемые в процессе решения величины

	const Line* Data;						// константный указатель на соответствующий Line
	int start;								// индекс первой '*'
	int end;								// индекс последней '*'
	Line* StatPict;							// запоминает состояние строки для сравнения с Data
	bool isFull;							// индикатор того заполнена ли строка полностью
	std::vector<NumberAndBorders> numInfo;	// вектор, хранящий все числа в Data

public:
	Condition(const std::vector<int>& info);
};
