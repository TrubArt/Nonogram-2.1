#include "../headers/Condition.h"

Condition::Condition(int lineSize, const Line* ptr, const std::vector<int>& info)
{
	data = ptr;
	start = 0;
	end = lineSize - 1;
	statLine = *data;
	isFull = false;

	allCountBlackCell = 0;

	for (int i = 0; i < info.size(); i++)
		numInfo.push_back(NumberAndBorders(info[i]));

	for (const auto& i : numInfo)
		allCountBlackCell += i.getNumber();

	allCountWhiteCell = lineSize - allCountBlackCell;
}

Condition::~Condition()
{
	// delete data не делается, тк за освобождение этого указателя отвечает класс Picture 
}

bool Condition::getisFullFlag() const
{
	return isFull;
}

std::string Condition::toString() const
{
	if (isFull)
		return "-\n";
	else
	{
		std::string answer;
		answer.append("\tНачало: " + std::to_string(start) + ", " + "Конец: " + std::to_string(end) + "\n");
		answer.append("\tСписок:");

		for (const auto& i : numInfo)
			answer.append(" " + i.toString());

		return answer.append("\n");
	}
}
