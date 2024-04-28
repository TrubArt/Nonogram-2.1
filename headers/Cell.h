#pragma once
#ifndef CELL_NONOGRAM
#define CELL_NONOGRAM
#include <iostream>
#include <string>

// ������������� ��� ���� ������ ����
enum class CellType
{
	undefined = -1,
	white,
	black
};

// ����� ������ ����
class Cell
{
	CellType cellType; //��� ������

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
#endif // !CELL_NONOGRAM
