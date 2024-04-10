#pragma once
#include "Picture.h"
#include "Condition.h"
#include <array>
#include <vector>
#include <string>

class Solution
{
	// enum дл€ обращени€ к строкам/столбцам в conditions
	enum lineClassifier { row, col };

	Picture* pict;
	std::array<std::vector<Condition*>, 2> conditions;

public:

	/// <param name="fileCondition:">файл с услови€ми строк</param>
	/// <param name="fileAdditCondit:">файл с доп услови€ми цвета</param>
	Solution(const std::string& fileCondition, const std::string& fileAdditCondit);
	Solution(const Solution&) = delete;
	~Solution();

	Solution& operator=(const Solution&) = delete;

	Picture getPicture() const;
	bool isEndOfWork() const;

	// метод, представл€ющий из себ€ шаблон дл€ прогонки каждого метода
	void callingMethods();
	std::string pictToString() const;
	std::string conditionsToString() const;

private:
	void switchFunction(int funNum, int rowOrCol, int positionInRowOrCol);
	void method1(int rowOrCol, int positionInRowOrCol);
	void method2(int rowOrCol, int positionInRowOrCol);
};
