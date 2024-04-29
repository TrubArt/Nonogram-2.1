#pragma once
#ifndef NUMBER_NONOGRAM
#define NUMBER_NONOGRAM
#include "Line.h"
#include <string>

// �����, �������� ����� � ��� ��������������
class NumberAndBorders
{
	typedef std::pair<int, int> myP;

	int number;		// �����
	myP dia;		// (D) ��������, � ������� ����� ������������ ���������� �����
	bool isExistRD;	// ����, ������������, ���������� �� �������� ��������
	myP realDia;	// (RD) ��������, � ������� ��������� ������ ��� �����

public:
	// constructors, destructor, operators

	NumberAndBorders(int number, const myP& dia, const myP& realdia);

	// getters & setters

	int getNum() const;
	const myP& getD() const;
	const myP& getRD() const;
	bool getFlagExistRd() const;
	void setD(const myP& x);
	void setFlagExistRd(bool flag);
	void setRD(const myP& x);

	// functions

	void updateNumberAndBorders(const Line* const data);
	std::string toString() const;

private:
	// ���������� RD �� ������ D, �� RD �� ����� �������� �� ������� D
	void updateRDviaD();

	// �������� D, ���� � RD ���� ���� ���� black ������
	void updateDviaRD(const Line* const data);
};
#endif // !NUMBER_NONOGRAM
