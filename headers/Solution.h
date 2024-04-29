#pragma once
#ifndef SOLUTION_NONOGRAM
#define SOLUTION_NONOGRAM
#include "Picture.h"
#include "Condition.h"
#include <array>
#include <vector>
#include <string>

// основной класс, реализующий методы по решению нонограммы
class Solution
{
	// enum для обращения к строкам/столбцам в conditions
	enum lineClassifier { row, col };

	Picture* pict;										// изображение в котором закрашиваются клетки
	std::array<std::vector<Condition*>, 2> conditions;	// массив с условиями для строк и столбцов

public:
	// constructors, destructor, operators
	
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
	void callingMethods();
	std::string pictToString() const;
	std::string conditionsToString() const;

private:
	void switchFunction(int funNum, int rowOrCol, int positionInRowOrCol);

	// метод, который закрашивает все CellType::undefined в цвет param
	void methodLastSet(int rowOrCol, int positionInRowOrCol, updCondReturnParam param);

	// если start || end == 1, то однозначно закрашивает клетки принадлежащие первому/последнему числу
	void methodStartEndNum(int rowOrCol, int positionInRowOrCol);

	void method1(int rowOrCol, int positionInRowOrCol);
	void method2(int rowOrCol, int positionInRowOrCol);

	// закраска strOrCol под номером positionInRowOrCol позиции index цветом Ctype
	void setColorWithInformation(int rowOrCol, int positionInRowOrCol, int index, CellType Ctype);
};
#endif // !SOLUTION_NONOGRAM
