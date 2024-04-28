#pragma once
#ifndef CONITION_NONOGRAM
#define CONITION_NONOGRAM
#include "Line.h"
#include "NumberAndBorder.h"
#include <string>
#include <list>

// enum ��� ���� ������������ �������� ������� updateCondition()
enum class updCondReturnParam
{
	LineNotCompleted = -1,
	SetWhite,
	SetBlack
};

// ��� ������ � ������ ���������� ������ � ���� ������ � ������ NumberAndBorders
// ����� ������ �������� ����������(������������)

// �����, �������� � ���� ��������� �� ������ � ���������� �������������� ���� ������
class Condition
{
	// ������������ � �������� ������� ��������

	int allCountWhiteCell;					// ����� ���������� ����� ������ - '0'
	int allCountBlackCell;					// ����� ���������� ������ ������ - '1'
	const Line* const data;					// ����������� ��������� �� ��������������� Line

	// ���������� � �������� ������� ��������

	bool isFull;							// ��������� ���� ��������� �� ������ ���������
	int start;								// ������ ������ '*'
	int end;								// ������ ����� ��������� '*'
	Line statLine;							// ���������� ��������� ������ ��� ��������� � data
	std::list<NumberAndBorders> numInfo;	// ������, �������� ��� ����� �� data

public:
	// constructors, destructor, operators

	Condition() = delete;
	Condition(int lineSize, const Line* const ptr, const std::vector<int>& info);
	Condition(const Condition&) = delete;
	~Condition();
	Condition& operator=(const Condition&) = delete;

	// getters & setters

	bool getIsFullFlag() const;
	const Line* const getLinePtr() const;
	int getStart() const;
	int getEnd() const;
	const std::list<NumberAndBorders>& getNumInfo() const;

	// functions

	updCondReturnParam updateCondition();
	std::string toString() const;

private:
	void updateStart();
	void updateEnd();
	void updateBorders();

	// ��������� Dia(���� ����� ������� ����� ������), �������� ��� ������� ����� ������� ��� �������������
	// ��� ����������� ������� ����������� ���� ����� ����� �������
	void updateDia();

	// ��������� realDia(���� ����� ������� ����� ������), �������� 
	// ���������� �� �������� ����� ��������� ��������� �������� �����
	void updateRealDia();
};
#endif // !CONITION_NONOGRAM
