#pragma once
#ifndef LINE_NONOGRAM
#define LINE_NONOGRAM
#include "Cell.h"
#include <iostream>
#include <string>
#include <vector>

// ����� �����, ���������� ������ ������
class Line
{
	std::vector<Cell*> data;	// ������ ������
	// ������� �� ����� ���������

public:
	// constructors, destructor, operators

	Line() = default;
	Line(int size);
	Line(const Line& x);
	~Line();
	Line& operator=(const Line& x);
	bool operator==(const Line& x) const;
	bool operator!=(const Line& x) const;

	// getters & setters

	void setCellType(int index, CellType Ctype);
	CellType getCellType(int index) const;
	size_t getSize() const;

	// functions

	// ���������� ���������� ������ ���� Ctype � Line
	int getCountTypeCell(CellType Ctype) const;

	// ���������� ���������� ������ ���� Ctype � ���������[startIndex, endIndex) � Line
	int getCountTypeCell(int startIndex, int endIndex, CellType Ctype) const;

	// ���������� ������ ������ ����� ���� Ctype � ���������[startIndex, endIndex) � Line
	int getLeftIndexTypeCell(int startIndex, int endIndex, CellType Ctype) const;

	// ���������� ������ ������ ������ ���� Ctype � ���������[startIndex, endIndex) � Line
	int getRightIndexTypeCell(int startIndex, int endIndex, CellType Ctype) const;

	std::string toString() const;
	friend std::ostream& operator<<(std::ostream& out, const Line& line);
};
#endif // !LINE_NONOGRAM
