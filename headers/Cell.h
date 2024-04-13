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
	// constructors, destructor, operators
	Cell();
	Cell(CellType Ctype);

	// getters & setters
	void set(CellType Ctype);
	CellType get() const;

	// functions
	std::string toString() const;
	friend std::ostream& operator<<(std::ostream& out, const Cell& cell);
};
