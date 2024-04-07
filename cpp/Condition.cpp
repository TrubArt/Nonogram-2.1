#include "../headers/Condition.h"

Condition::Condition(int lineSize, const std::vector<int>& info)
{
	data = nullptr;
	start = 0;
	end = lineSize - 1;
	statLine = nullptr;
	isFull = false;

	for (int i = 0; i < info.size(); i++)
		numInfo.push_back(NumberAndBorders(info[i]));

	for (const auto& i : numInfo)
		allCountBlackCell += i.getNumber();

	allCountWhiteCell = lineSize - allCountBlackCell;
}

Condition::~Condition()
{
	// delete data �� ��������, �� �� ������������ ����� ��������� �������� ����� Picture 
	delete statLine;
}

std::string Condition::toString() const
{
	if (isFull)
		return "-\n";
	else
	{
		std::string answer;
		answer.append("\t������: " + std::to_string(start) + ", " + "�����: " + std::to_string(end) + "\n");
		answer.append("\t������:");

		for (const auto& i : numInfo)
			answer.append(" " + i.toString());

		return answer.append("\n");
	}
}
