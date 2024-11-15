#pragma once
#ifndef SOLUTION_NONOGRAM
#define SOLUTION_NONOGRAM
#include "Picture.h"
#include "Condition.h"
#include "../methods/IMethod.h"
#include <array>
#include <vector>
#include <string>

// основной класс, реализующий методы по решению нонограммы
class Solution
{
	Picture* pict;										// изображение в котором закрашиваются клетки
	std::array<std::vector<Condition*>, 2> conditions;	// массив с условиями для строк и столбцов

public:
	// ctors, dctor, operators
	
	Solution() = delete;

	/// <param name="fileCondition:">файл с условиями строк</param>
	/// <param name="fileAdditCondit:">файл с доп условиями цвета</param>
	Solution(const std::string& fileCondition, const std::string& fileAdditCondit);

	Solution(const Solution&) = delete;
	~Solution();
	Solution& operator=(const Solution&) = delete;

	// getters & setters

	Picture getPicture() const;
	bool isEndOfWork() const;

	// functions

	// метод, представляющий из себя шаблон для прогонки каждого метода
	void callingMethods(const std::vector<IMethod*>& methods);

	// выводит в консоль this, подсвечивая color различия между this и cond
	void printToConsoleConditionDifferences(const std::array<std::vector<Condition*>, 2>& cond, int color) const;
	std::string pictToString() const;
	std::string conditionsToString() const;
};
#endif // !SOLUTION_NONOGRAM
