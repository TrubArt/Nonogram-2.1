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
	// constructors, destructor, operators
	NumberAndBorders(int number);

	// getters & setters
	int getNumber() const;

	// functions
	void updateNumberAndBorders();
	std::string toString() const;
};