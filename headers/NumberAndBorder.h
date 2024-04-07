#pragma once
#include <string>

// �����, �������� ����� � ��� ��������������
// Dia - ��������, � ������� ����� ������������ ���������� �����
// RealDia - ��������, � ������� ��������� ������ ��� �����
class NumberAndBorders
{
	int number;			// �����
	int startDia;		// ������ Dia
	int endDia;			// ����� Dia
	int startRealDia;	// ������ RealDia
	int endRealDia;		// ����� RealDia

public:

	NumberAndBorders(int i);
	int getNumber() const;
	std::string toString() const;
};