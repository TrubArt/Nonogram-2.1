#pragma once
#include "Line.h"
#include "NumberAndBorder.h"
#include <string>
#include <vector>

// �����, �������� � ���� ��������� �� ������ � ���������� �������������� ���� ������
class Condition
{
	// ������������ � �������� ������� ��������

	int allCountWhiteCell;			// ����� ���������� ����� ������ - '0'
	int allCountBlackCell;			// ����� ���������� ������ ������ - '1'

	// ���������� � �������� ������� ��������

	const Line* data;						// ����������� ��������� �� ��������������� Line
	int start;								// ������ ������ '*'
	int end;								// ������ ��������� '*'
	Line* statLine;							// ���������� ��������� ������ ��� ��������� � data
	bool isFull;							// ��������� ���� ��������� �� ������ ���������
	std::vector<NumberAndBorders> numInfo;	// ������, �������� ��� ����� �� data

public:
	Condition(int lineSize, const std::vector<int>& info);
	Condition(const Condition&) = delete;
	~Condition();

	Condition& operator=(const Condition&) = delete;

	std::string toString() const;
};
