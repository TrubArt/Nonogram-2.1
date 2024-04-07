#pragma once
#include <iostream>
#include <string>

// перечислитель для вида клетки поля
enum class CellType
{
	undefined = -1,
	white,
	black
};

// класс клетки поля
class Cell
{
	CellType cellType; //тип клетки

public:
	Cell();
	Cell(CellType Ctype);
	void set(CellType Ctype);
	CellType get() const;

	std::string toString() const;
	friend std::ostream& operator<<(std::ostream& out, const Cell& cell);
};
