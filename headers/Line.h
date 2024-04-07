#pragma once
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
	Line() = default;
	Line(int size);
	Line(const Line& x);
	~Line();

	Line& operator=(const Line& x);
	bool operator==(const Line& x) const;
	bool operator!=(const Line& x) const;

	void setCellType(int i, CellType Ctype);
	CellType getCellType(int i) const;
	size_t getSize() const;

	/// <param name="Ctype:"> тип искомых клеток</param>
	/// <returns>Число клеток типа Ctype в линии</returns>
	int getCountTypeCell(CellType Ctype) const;

	std::string toString() const;

	friend std::ostream& operator<<(std::ostream& out, const Line& line);
};
