#pragma once
#include "Line.h"
#include <iostream>
#include <vector>
#include <string>

// �����, �������� �����������
class Picture
{
	std::vector<Line*> rows;	// ������ �����
	std::vector<Line*> columns;	// ������ ��������

public:
	// constructors, destructor, operators
	Picture(int N, int M);
	Picture(const Picture& x);
	~Picture();
	Picture& operator=(const Picture& x);
	bool operator==(const Picture& x) const;
	bool operator!=(const Picture& x) const;

	// getters & setters
	const Line* getPtr(std::pair<int, int> x) const;
	void setColor(int rowNumber, int index, CellType Ctype);

	// functions
	std::string toString() const;
	friend std::ostream& operator<<(std::ostream& out, const Picture& pict); // ������ �����������
};
