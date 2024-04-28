#include "../headers/Condition.h"

Condition::Condition(int lineSize, const Line* const ptr, const std::vector<int>& info) : data{ ptr }, statLine(lineSize + 1) // ������ *data != statLine
{
	start = 0;
	end = lineSize;
	isFull = false;

	allCountBlackCell = 0;

	for (int i = 0; i < static_cast<int>(info.size()); ++i)
	{
		numInfo.push_back(NumberAndBorders(info[i], std::make_pair(start, end), std::make_pair(start, end)));
	}
	this->updateBorders();

	for (const auto& i : numInfo)
	{
		allCountBlackCell += i.getNum();
	}

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

const Line* const Condition::getLinePtr() const
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
		this->updateBorders();

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
		{
			answer.append(" " + i.toString());
		}

		return answer.append("\n");
	}
}

void Condition::updateStart()
{
	if (start >= end)
		return;

	while (data->getCellType(start) != CellType::undefined)
	{
		if (data->getCellType(start) == CellType::white) 
			++start;
		else
		{
			// ������ ������ �������������� ������� methodStartEndNum. �� ����������� ����������� ������.
			// ����� �� ������� ������ �������� ������ � ������
			int number = numInfo.front().getNum();
			numInfo.pop_front();
			start += number + 1;
		}

		if (start >= end)
			return;
	}
}

void Condition::updateEnd()
{
	if (start >= end)
		return;

	while (data->getCellType(end - 1) != CellType::undefined)
	{
		if (data->getCellType(end - 1) == CellType::white) 
			--end;
		else
		{
			// ������ ������ �������������� ������� methodStartEndNum. �� ����������� ����������� ������.
			// ����� �� ������� ������ �������� ������ � �����
			int number = numInfo.back().getNum();
			numInfo.pop_back();
			end -= number + 1;
		}

		if (start >= end)
			return;
	}
}

void Condition::updateBorders()
{
	this->updateDia();
	this->updateRealDia();
	for (auto& i : numInfo)
		i.updateNumberAndBorders(data);
}

void Condition::updateDia()
{
	enum helpEnum {space = 1};	// enum ������������ ������(���� CellType::whiteCell)

	int leftNums = start;		// ���������� ������� ������ ����� �� �������� �����
	int rightNums = end;		// ���������� ������� ������ ������ �� �������� �����
	for (auto it = numInfo.begin(); it != numInfo.end(); ++it)	// ����� ����������� ��������� ���������
	{
		rightNums -= it->getNum() + space;
	}

	// ������� ��� ������� ����� ��� ��������

	for (auto it = numInfo.begin(); it != numInfo.end(); ++it)
	{
		rightNums += it->getNum() + space;	// ���������� �������� ����� �����

		if (leftNums > it->getD().first)	// ��������e startDia
			it->setD(std::make_pair(leftNums, it->getD().second));
		if (rightNums < it->getD().second)	// ��������e endDia
			it->setD(std::make_pair(it->getD().first, rightNums));

		leftNums += it->getNum() + space;	// ���������� �������� ����� ������
	}
}

void Condition::updateRealDia()
{
	int leftBorder = start;
	int rightBorder = -1;

	for (auto it = numInfo.begin(); it != numInfo.end(); ++it)
	{
		auto ittmp = it;
		// ����������� rightBorder
		if (it == --numInfo.end())
			rightBorder = end;
		else
			rightBorder = (++ittmp)->getD().first;

		if (leftBorder < rightBorder)	// �������� ��� � ����� ��������� ���� ���� �� 1 ������
		{
			it->setFlagExistRd(true);	// ������ �������� ��������

			if (leftBorder > it->getRD().first)		// ��������e startRDia
				it->setRD(std::make_pair(leftBorder, it->getRD().second));
			if (rightBorder < it->getRD().second)	// ��������e endRDia
				it->setRD(std::make_pair(it->getRD().first, rightBorder));
		}

		// ����������� next leftBorder
		leftBorder = it->getD().second;
	}
}
