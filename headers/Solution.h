#pragma once
#include "Picture.h"
#include "Condition.h"
#include <array>
#include <vector>
#include <string>

class Solution
{
	// enum ��� ��������� � �������/�������� � conditions
	enum lineClassifier { row, col };

	Picture* pict;
	std::array<std::vector<Condition*>, 2> conditions;

public:

	/// <param name="fileCondition:">���� � ��������� �����</param>
	/// <param name="fileAdditCondit:">���� � ��� ��������� �����</param>
	Solution(const std::string& fileCondition, const std::string& fileAdditCondit);
	Solution(const Solution&) = delete;
	~Solution();

	Solution& operator=(const Solution&) = delete;

	Picture getPicture() const;
	bool isEndOfWork() const;

	// �����, �������������� �� ���� ������ ��� �������� ������� ������
	void callingMethods();
	std::string pictToString() const;
	std::string conditionsToString() const;

private:
	void switchFunction(int funNum, int rowOrCol, int positionInRowOrCol);
	void method1(int rowOrCol, int positionInRowOrCol);
	void method2(int rowOrCol, int positionInRowOrCol);
};
