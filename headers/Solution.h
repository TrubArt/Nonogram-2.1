#pragma once
#ifndef SOLUTION_NONOGRAM
#define SOLUTION_NONOGRAM
#include "Picture.h"
#include "Condition.h"
#include <array>
#include <vector>
#include <string>

// �������� �����, ����������� ������ �� ������� ����������
class Solution
{
	// enum ��� ��������� � �������/�������� � conditions
	enum lineClassifier { row, col };

	Picture* pict;										// ����������� � ������� ������������� ������
	std::array<std::vector<Condition*>, 2> conditions;	// ������ � ��������� ��� ����� � ��������

public:
	// constructors, destructor, operators
	
	Solution() = delete;

	/// <param name="fileCondition:">���� � ��������� �����</param>
	/// <param name="fileAdditCondit:">���� � ��� ��������� �����</param>
	Solution(const std::string& fileCondition, const std::string& fileAdditCondit);

	Solution(const Solution&) = delete;
	~Solution();
	Solution& operator=(const Solution&) = delete;

	// getters & setters

	Picture getPicture() const;
	bool isEndOfWork() const;

	// functions

	// �����, �������������� �� ���� ������ ��� �������� ������� ������
	void callingMethods();
	std::string pictToString() const;
	std::string conditionsToString() const;

private:
	void switchFunction(int funNum, int rowOrCol, int positionInRowOrCol);

	// �����, ������� ����������� ��� CellType::undefined � ���� param
	void methodLastSet(int rowOrCol, int positionInRowOrCol, updCondReturnParam param);

	// ���� start || end == 1, �� ���������� ����������� ������ ������������� �������/���������� �����
	void methodStartEndNum(int rowOrCol, int positionInRowOrCol);

	void method1(int rowOrCol, int positionInRowOrCol);
	void method2(int rowOrCol, int positionInRowOrCol);

	// �������� strOrCol ��� ������� positionInRowOrCol ������� index ������ Ctype
	void setColorWithInformation(int rowOrCol, int positionInRowOrCol, int index, CellType Ctype);
};
#endif // !SOLUTION_NONOGRAM
