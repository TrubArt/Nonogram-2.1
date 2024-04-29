#pragma once
#ifndef CONITION_NONOGRAM
#define CONITION_NONOGRAM
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

// все данные о строке изменяются только в этом классе и классе NumberAndBorders
// извне данные поменять невозможно(инкапсуляция)

// класс, хранящий в себе указатель на строку и содержащий характеристики этой строки
class Condition
{
	// неизменяемые в процессе решения величины

	int allCountWhiteCell;					// общее количество белых клеток - '0'
	int allCountBlackCell;					// общее количество чёрных клеток - '1'
	const Line* const data;					// константный указатель на соответствующий Line

	// изменяемые в процессе решения величины

	bool isFull;							// индикатор того заполнена ли строка полностью
	int start;								// индекс первой '*'
	int end;								// индекс после последней '*'
	Line statLine;							// запоминает состояние строки для сравнения с data
	std::list<NumberAndBorders> numInfo;	// список, хранящий все числа из data

public:
	// constructors, destructor, operators

	Condition() = delete;
	Condition(int lineSize, const Line* const ptr, const std::vector<int>& info);
	Condition(const Condition&) = delete;
	~Condition();
	Condition& operator=(const Condition&) = delete;

	// getters & setters

	bool getIsFullFlag() const;
	const Line* const getLinePtr() const;
	int getStart() const;
	int getEnd() const;
	const std::list<NumberAndBorders>& getNumInfo() const;

	// functions

	updCondReturnParam updateCondition();
	std::string toString() const;

private:
	void updateStart();
	void updateEnd();
	void updateBorders();

	// обновляет Dia(если новые границы лучше старых), проверяя для каждого числа границы его существования
	// при максимально плотной расстановке всех чисел кроме данного
	void updateDia();

	// обновляет realDia(если новые границы лучше старых), проверяя 
	// существует ли диапазон между реальными границами соседних чисел
	void updateRealDia();
};
#endif // !CONITION_NONOGRAM
