#pragma once
#include "Picture.h"
#include "Condition.h"
#include <iostream>
#include <array>
#include <vector>
#include <string>

class Solution
{
	Picture pict;
	std::array<std::vector<Condition*>, 2> condions;

public:

	Solution(const std::string& Condition, const std::string& AdditCondit);

	std::string pictToString() const;
	std::string conditionsToString() const;
};
