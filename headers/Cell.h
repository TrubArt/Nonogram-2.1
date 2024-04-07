#pragma once
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
	Cell();
	Cell(CellType Ctype);
	void set(CellType Ctype);
	CellType get() const;

	std::string toString() const;
	friend std::ostream& operator<<(std::ostream& out, const Cell& cell);
};
