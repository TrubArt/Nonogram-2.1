#pragma once
#include "Line.h"
#include "NumberAndBorder.h"
#include <string>
#include <list>

// enum для типа возращаемого значения функции updateCondition()
enum class updCondReturnParam 
{
	LineNotCompleted = -1,
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

	bool isFull;							// индикатор того заполнена ли строка полностью
	int start;								// индекс первой '*'
	int end;								// индекс после последней '*'
	Line statLine;							// запоминает состояние строки для сравнения с data
	std::list<NumberAndBorders> numInfo;	// список, хранящий все числа из data

public:
	// constructors, destructor, operators
	Condition(int lineSize, const Line* ptr, const std::vector<int>& info);
	Condition(const Condition&) = delete;
	~Condition();
	Condition& operator=(const Condition&) = delete;

	// getters & setters
	bool getIsFullFlag() const;
	const Line* getLinePtr() const;
	int getStart() const;
	int getEnd() const;
	const std::list<NumberAndBorders>& getNumInfo() const;

	// functions
	updCondReturnParam updateCondition();
	std::string toString() const;
private:
	void updateStart();
	void updateEnd();
};
