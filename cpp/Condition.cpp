#include "../headers/Condition.h"

Condition::Condition(int lineSize, const Line* ptr, const std::vector<int>& info) : data{ ptr }, statLine(lineSize + 1) // ������ *data != statLine
{
	start = 0;
	end = lineSize - 1;
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

bool Condition::getIsFullFlag() const
{
	return isFull;
}

const Line* Condition::getLinePtr() const
{
	return data;
}

int Condition::getStart() const
{
	return start;
}

int Condition::getEnd() const
{
	return end;
}

const std::list<NumberAndBorders>& Condition::getNumInfo() const
{
	return numInfo;
}

updCondReturnParam Condition::updateCondition()
{
	if (*data != statLine)
	{
		statLine = *data; // ��������� ��������� ������ �� �����������

		// ���������� start
		this->updateStart();

		// ���������� start
		this->updateEnd();

		// ���������� ���������� � numInfo
		for (auto& i : numInfo)
			i.updateNumberAndBorders();

		// �������� �� ��, ��� ������ ����� ���������� ����������
		if (data->getCountTypeCell(CellType::white) == allCountWhiteCell)
		{
			isFull = true;
			return updCondReturnParam::SetBlack;
		}
		if (data->getCountTypeCell(CellType::black) == allCountBlackCell)
		{
			isFull = true;
			return updCondReturnParam::SetWhite;
		}
	}

	return updCondReturnParam::LineNotCompleted;
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

void Condition::updateStart()
{
	if (start > end)
		return;

	while (data->getCellType(start) != CellType::undefined)
	{
		if (data->getCellType(start) == CellType::white) start++;
		else
		{
			// ������ ������ �������������� ������� methodStartEndNum. �� ����������� ����������� ������.
			// ����� �� ������� ������ �������� ������ � ������
			int number = numInfo.front().getNumber();
			numInfo.pop_front();
			start += number + 1;
		}

		if (start > end)
			return;
	}
}

void Condition::updateEnd()
{
	if (start > end)
		return;

	while (data->getCellType(end) != CellType::undefined)
	{
		if (data->getCellType(end) == CellType::white) end--;
		else
		{
			// ������ ������ �������������� ������� methodStartEndNum. �� ����������� ����������� ������.
			// ����� �� ������� ������ �������� ������ � �����
			int number = numInfo.back().getNumber();
			numInfo.pop_back();
			end -= number + 1;
		}

		if (start > end)
			return;
	}
}
