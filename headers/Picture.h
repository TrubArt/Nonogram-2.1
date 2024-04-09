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
	Picture(int N, int M);
	Picture(const Picture& x);
	~Picture();

	Picture& operator=(const Picture& x);
	bool operator==(const Picture& x) const;
	bool operator!=(const Picture& x) const;

	const Line* getPtr(std::pair<int, int> x) const;
	void colorSet(int i, int j, CellType type);
	std::string toString() const;
	friend std::ostream& operator<<(std::ostream& out, const Picture& pict); // ������ �����������
};
