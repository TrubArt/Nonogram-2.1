﻿#pragma once
#ifndef LINE_NONOGRAM
#define LINE_NONOGRAM
#include "Cell.h"
#include <iostream>
#include <string>
#include <vector>

// класс линии, содержащей вектор клеток
class Line
{
	std::vector<Cell*> data;	// вектор клеток
	// переход на умные указатели

public:
	// constructors, destructor, operators

	Line() = default;
	Line(size_t size);
	Line(const Line& x);
	~Line();
	Line& operator=(const Line& x);
	bool operator==(const Line& x) const;
	bool operator!=(const Line& x) const;

	// getters & setters

	void setCellType(size_t index, CellType cType);
	CellType getCellType(size_t index) const;
	size_t getSize() const;

	// functions

	// возвращает количество клеток типа cType в Line
	int getCountTypeCell(CellType cType) const;

	// возвращает количество клеток типа cType в диапазоне[startIndex, endIndex) в Line
	int getCountTypeCell(size_t startIndex, size_t endIndex, CellType cType) const;

	// возвращает первый индекс слева типа cType в диапазоне[startIndex, endIndex) в Line
	int getLeftIndexTypeCell(size_t startIndex, size_t endIndex, CellType cType) const;

	// возвращает первый индекс справа типа cType в диапазоне[startIndex, endIndex) в Line
	int getRightIndexTypeCell(size_t startIndex, size_t endIndex, CellType cType) const;

	// выводит в консоль this, подсвечивая color различия между this и line
	void printToConsoleDifferences(const Line& line, int color) const;

	// выводит в консоль Line, где CellType::white подсвечены цветом whiteColor, а подсвечены цветом CellType::black blackColor
	void printToConsoleColor(int whiteColor, int blackColor) const;
	std::string toString() const;
	friend std::ostream& operator<<(std::ostream& out, const Line& line);
};
#endif // !LINE_NONOGRAM
