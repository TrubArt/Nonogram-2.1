#pragma once
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

	/// <param name="Ctype:"> ��� ������� ������</param>
	/// <returns>����� ������ ���� Ctype � �����</returns>
	int getCountTypeCell(CellType Ctype) const;
	std::string toString() const;
	friend std::ostream& operator<<(std::ostream& out, const Line& line);
};
