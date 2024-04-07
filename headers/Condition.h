#pragma once
#include "Line.h"
#include <vector>

class Condition
{
	struct NumberAndBorders
	{
		int number;			// �����
		int startDia;		// Dia - ��������, � ������� ����� ������������ ���������� �����
		int endDia;			// 
		int startRealDia;	// RealDia - ��������, � ������� ��������� ������ ��� �����
		int endRealDia;		// 
	};

	// ������������ � �������� ������� ��������

	int CNField;			// conditionNecessaryField - '1'
	int CUField;			// conditionUnnecessaryField - '0'

	// ���������� � �������� ������� ��������

	const Line* Data;						// ����������� ��������� �� ��������������� Line
	int start;								// ������ ������ '*'
	int end;								// ������ ��������� '*'
	Line* StatPict;							// ���������� ��������� ������ ��� ��������� � Data
	bool isFull;							// ��������� ���� ��������� �� ������ ���������
	std::vector<NumberAndBorders> numInfo;	// ������, �������� ��� ����� � Data

public:
	Condition(const std::vector<int>& info);
};
