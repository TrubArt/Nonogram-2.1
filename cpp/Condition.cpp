#include "../headers/Condition.h"

Condition::Condition(int lineSize, const Line* ptr, const std::vector<int>& info) : data{ ptr }
{
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
	// delete data не делаетс€, тк за освобождение этого указател€ отвечает класс Picture 
}

bool Condition::getisFullFlag() const
{
	return isFull;
}

updCondReturnParam Condition::updateCondition()
{
	if (*data != statLine)
	{
		statLine = *data; // обновл€ем состо€ние строки до актуального

		// обновление start и end

		// обновление диапазонов
		for (auto& i : numInfo)
			i.updateNumberAndBorders();

		// проверка на то, что строку можно однозначно определить
		if (data->getCountTypeCell(CellType::white) == allCountWhiteCell)
		{
			isFull = true;
			return updCondReturnParam::SetWhite;
		}
		if (data->getCountTypeCell(CellType::black) == allCountBlackCell)
		{
			isFull = true;
			return updCondReturnParam::SetBlack;
		}
	}

	return updCondReturnParam::NothingToUpdate;
}

std::string Condition::toString() const
{
	if (isFull)
		return "-\n";
	else
	{
		std::string answer;
		answer.append("\tЌачало: " + std::to_string(start) + ", " + " онец: " + std::to_string(end) + "\n");
		answer.append("\t—писок:");

		for (const auto& i : numInfo)
			answer.append(" " + i.toString());

		return answer.append("\n");
	}
}
