#pragma once
#include "Line.h"
#include "NumberAndBorder.h"
#include <string>
#include <vector>

// класс, хранящий в себе указатель на строку и содержащий характеристики этой строки
class Condition
{
	// неизменяемые в процессе решения величины

	int allCountWhiteCell;			// общее количество белых клеток - '0'
	int allCountBlackCell;			// общее количество чёрных клеток - '1'

	// изменяемые в процессе решения величины

	const Line* data;						// константный указатель на соответствующий Line
	int start;								// индекс первой '*'
	int end;								// индекс последней '*'
	Line* statLine;							// запоминает состояние строки для сравнения с data
	bool isFull;							// индикатор того заполнена ли строка полностью
	std::vector<NumberAndBorders> numInfo;	// вектор, хранящий все числа из data

public:
	Condition(int lineSize, const std::vector<int>& info);
	Condition(const Condition&) = delete;
	~Condition();

	Condition& operator=(const Condition&) = delete;

	std::string toString() const;
};
