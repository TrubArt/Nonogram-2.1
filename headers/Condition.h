#pragma once
#include "Line.h"
#include "NumberAndBorder.h"
#include <string>
#include <vector>

enum class updCondReturnParam 
{
	NothingToUpdate = -1,
	SetWhite,
	SetBlack
};

// класс, хранящий в себе указатель на строку и содержащий характеристики этой строки
class Condition
{
	// неизменяемые в процессе решения величины

	int allCountWhiteCell;				// общее количество белых клеток - '0'
	int allCountBlackCell;				// общее количество чёрных клеток - '1'
	const Line* const data;				// константный указатель на соответствующий Line

	// изменяемые в процессе решения величины

	int start;								// индекс первой '*'
	int end;								// индекс последней '*'
	Line statLine;							// запоминает состояние строки для сравнения с data
	bool isFull;							// индикатор того заполнена ли строка полностью
	std::vector<NumberAndBorders> numInfo;	// вектор, хранящий все числа из data

public:
	Condition(int lineSize, const Line* ptr, const std::vector<int>& info);
	Condition(const Condition&) = delete;
	~Condition();
	Condition& operator=(const Condition&) = delete;

	bool getisFullFlag() const;
	updCondReturnParam updateCondition();
	std::string toString() const;
};
