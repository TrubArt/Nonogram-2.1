#pragma once
#include "Picture.h"
#include "Condition.h"
#include <array>
#include <vector>
#include <string>

class Solution
{
	Picture* pict;
	std::array<std::vector<Condition*>, 2> conditions;

public:

	/// <param name="fileCondition:">���� � ��������� �����</param>
	/// <param name="fileAdditCondit:">���� � ��� ��������� �����</param>
	Solution(const std::string& fileCondition, const std::string& fileAdditCondit);
	Solution(const Solution&) = delete;
	~Solution();

	Solution& operator=(const Solution&) = delete;

	std::string pictToString() const;
	std::string conditionsToString() const;
};
