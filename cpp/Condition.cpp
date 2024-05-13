#include "../headers/Condition.h"

Condition::Condition(int lineSize, const Line* const ptr, const std::vector<int>& info) : data{ ptr }, statLine(lineSize + 1) // делаем *data != statLine
{
	start = 0;
	end = lineSize;
	isFull = false;

	allCountBlackCell = 0;

	for (int i = 0; i < static_cast<int>(info.size()); ++i)
	{
		// данные для диапазонов передаются именно в таком формате, поскольку D - должен только сужаться, а RD - расширяться
		numInfo.push_back(NumberAndBorders(info[i], std::make_pair(start, end), std::make_pair(end, start)));
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
	// delete data не делается, тк за освобождение этого указателя отвечает класс Picture 
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

UpdCondReturnParam Condition::updateCondition()
{
	if (*data != statLine)
	{
		statLine = *data; // обновляем состояние строки до актуального

		// обновление start
		this->updateStart();

		// обновление start
		this->updateEnd();

		// обновление диапазонов в numInfo
		this->updateBorders();

		// проверка на то, что строку можно однозначно определить
		if (data->getCountTypeCell(CellType::white) == allCountWhiteCell)
		{
			isFull = true;
			return UpdCondReturnParam::setBlack;
		}
		if (data->getCountTypeCell(CellType::black) == allCountBlackCell)
		{
			isFull = true;
			return UpdCondReturnParam::setWhite;
		}
	}

	return UpdCondReturnParam::lineNotCompleted;
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
			// данный случай обрабатывается методом StartEndNum. Он закрашивает необходимые клетки.
			// здесь же остаётся только обновить данные о начале
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
			// данный случай обрабатывается методом StartEndNum. Он закрашивает необходимые клетки.
			// здесь же остаётся только обновить данные о конце
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
	enum helpEnum {space = 1};	// enum обозначающий пробел(одна CellType::whiteCell)

	int leftNums = start;		// количество занятых клеток слева от текущего числа
	int rightNums = end;		// количество занятых клеток справа от текущего числа
	for (auto it = numInfo.begin(); it != numInfo.end(); ++it)	// задаём посчитанные начальные параметры
	{
		rightNums -= it->getNum() + space;
	}

	// считаем для каждого числа его диапазон

	for (auto it = numInfo.begin(); it != numInfo.end(); ++it)
	{
		rightNums += it->getNum() + space;	// добавление текущего числа слева

		if (leftNums > it->getD().first)	// улучшениe startDia
			it->setD(std::make_pair(leftNums, it->getD().second));
		if (rightNums < it->getD().second)	// улучшениe endDia
			it->setD(std::make_pair(it->getD().first, rightNums));

		leftNums += it->getNum() + space;	// добавление текущего числа справа
	}
}

void Condition::updateRealDia()
{
	int leftBorder = start;
	int rightBorder = -1;

	for (auto it = numInfo.begin(); it != numInfo.end(); ++it)
	{
		auto ittmp = it;
		// определение rightBorder
		if (it == --numInfo.end())
			rightBorder = end;
		else
			rightBorder = (++ittmp)->getD().first;

		if (leftBorder < rightBorder)	// проверка что в таком диапазоне есть хотя бы 1 клетка
		{
			it->setFlagExistRd(true);	// найден реальный диапазон

			if (leftBorder < it->getRD().first)		// улучшениe startRDia
				it->setRD(std::make_pair(leftBorder, it->getRD().second));
			if (rightBorder > it->getRD().second)	// улучшениe endRDia
				it->setRD(std::make_pair(it->getRD().first, rightBorder));
		}

		// определение next leftBorder
		leftBorder = it->getD().second;
	}
}
