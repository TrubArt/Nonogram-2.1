﻿#pragma once
#ifndef PICTURE_NONOGRAM
#define PICTURE_NONOGRAM
#include "Line.h"
#include <iostream>
#include <vector>
#include <string>

// класс, хранящий изображение
class Picture
{
	std::vector<Line*> rows;	// вектор строк
	std::vector<Line*> columns;	// вектор столбцов

public:
	// constructors, destructor, operators

	Picture(int N, int M);
	Picture(const Picture& x);
	~Picture();
	Picture& operator=(const Picture& x);
	bool operator==(const Picture& x) const;
	bool operator!=(const Picture& x) const;

	// getters & setters

	const Line* const getPtr(const std::pair<int, int>& x) const;
	void setColor(int rowNumber, int index, CellType cType);

	// functions

	// выводит в консоль this, подсвечивая color различия между this и pict
	void printToConsoleDifferences(const Picture& pict, int color) const;

	// выводит в консоль Picture, где CellType::white подсвечены цветом whiteColor, а подсвечены цветом CellType::black blackColor
	void printToConsoleColor(int whiteColor, int blackColor) const;
	std::string toString() const;
	friend std::ostream& operator<<(std::ostream& out, const Picture& pict); // печать изображения
};
#endif // !PICTURE_NONOGRAM
