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
	// delete data �� ��������, �� �� ������������ ����� ��������� �������� ����� Picture 
}

bool Condition::getisFullFlag() const
{
	return isFull;
}

updCondReturnParam Condition::updateCondition()
{
	if (*data != statLine)
	{
		statLine = *data; // ��������� ��������� ������ �� �����������

		// ���������� start � end

		// ���������� ����������
		for (auto& i : numInfo)
			i.updateNumberAndBorders();

		// �������� �� ��, ��� ������ ����� ���������� ����������
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
		answer.append("\t������: " + std::to_string(start) + ", " + "�����: " + std::to_string(end) + "\n");
		answer.append("\t������:");

		for (const auto& i : numInfo)
			answer.append(" " + i.toString());

		return answer.append("\n");
	}
}
