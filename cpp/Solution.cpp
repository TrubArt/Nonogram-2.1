#include "../headers/Solution.h"
#include "../headers/FileLoader.h"
#include "../Constants.h"

Solution::Solution(const std::string& fileCondition, const std::string& fileAdditCondit)
{
	FileLoader cond(fileCondition);

	std::vector<int> tmp;

	// получение данных о размере изображени€
	tmp = cond.getNumbersSequence();
	int sizeN = tmp[0];
	int sizeM = tmp[1];

	pict = new Picture(sizeN, sizeM);
	conditions[row].resize(sizeN);
	conditions[col].resize(sizeM);

	// получение данных о строках и столбцах
	for (int i = 0; i < sizeN; i++)
		conditions[row][i] = new Condition(sizeM, pict->getPtr(std::make_pair(row, i)), cond.getNumbersSequence());
	for (int i = 0; i < sizeM; i++)
		conditions[col][i] = new Condition(sizeN, pict->getPtr(std::make_pair(col, i)), cond.getNumbersSequence());

	// добавление доп. цветов
	FileLoader f2(fileAdditCondit);
	while (!f2.isEmpty())
	{
		tmp = f2.getNumbersSequence();
		if (!tmp.empty())
			pict->setColor(tmp[0], tmp[1], static_cast<CellType>(tmp[2]));
	}
}

Solution::~Solution()
{
	delete pict;

	for (auto& i : conditions)
		for (auto& j : i)
			delete j;
}

Picture Solution::getPicture() const
{
	return *pict;
}

bool Solution::isEndOfWork() const
{
	for (int i = 0; i < static_cast<int>(conditions.size()); i++)
		for (int j = 0; j < static_cast<int>(conditions[i].size()); j++)
			if (!conditions[i][j]->getIsFullFlag())
				return false;
	return true;
}

void Solution::callingMethods()
{
	// цикл с прогоном всех методов
	for (int methodNum = 0; methodNum < numberOfMethods; methodNum++)
	{
		// двойной цикл дл€ прохода по всем строкам/столбцам
		for (int rowOrCol = 0; rowOrCol < static_cast<int>(conditions.size()); rowOrCol++)
			for (int positionInRowOrCol = 0; positionInRowOrCol < static_cast<int>(conditions[rowOrCol].size()); positionInRowOrCol++)
				if (!conditions[rowOrCol][positionInRowOrCol]->getIsFullFlag())		// если строка ещЄ не завершена
				{
					// вызов определЄнного метода
					this->switchFunction(methodNum, rowOrCol, positionInRowOrCol);

					// метод по определению числа с кра€ строки
					this->methodStartEndNum(rowOrCol, positionInRowOrCol);

					// изменение данных о строке после цикла
					updCondReturnParam updPar = conditions[rowOrCol][positionInRowOrCol]->updateCondition();
					if (updPar != updCondReturnParam::LineNotCompleted)	// если строка закончена, то однозначно закрашиваем оставшиес€ пол€
						this->methodLastSet(rowOrCol, positionInRowOrCol, updPar);
				}
	}
}

std::string Solution::pictToString() const
{
	return pict->toString();
}

std::string Solution::conditionsToString() const
{
	std::string answer;

	for (int i = 0; i < static_cast<int>(conditions.size()); i++)
		for (int j = 0; j < static_cast<int>(conditions[i].size()); j++)
		{
			answer.append(std::to_string(i) + " " + std::to_string(j) + ": ");
			answer.append(conditions[i][j]->toString());
		}

	return answer;
}

void Solution::switchFunction(int funNum, int rowOrCol, int positionInRowOrCol)
{
	switch (funNum)
	{
	case 0:
		this->method1(rowOrCol, positionInRowOrCol);
		break;
	case 1:
		this->method2(rowOrCol, positionInRowOrCol);
		break;
	default:
		std::cout << "ќшибка Solution::switchFunction. —уществует меньше методов, чем указано в Constants.h/numberOfMethods\n";
		break;
	}
}

void Solution::methodLastSet(int rowOrCol, int positionInRowOrCol, updCondReturnParam param)
{
	if (param != updCondReturnParam::LineNotCompleted)
	{
		const Line* analyzedLine = conditions[rowOrCol][positionInRowOrCol]->getLinePtr();
		for (int i = conditions[rowOrCol][positionInRowOrCol]->getStart(); i <= conditions[rowOrCol][positionInRowOrCol]->getEnd(); i++)
			if (analyzedLine->getCellType(i) == CellType::undefined)
				this->setColorWithInformation(rowOrCol, positionInRowOrCol, i, static_cast<CellType>(param));
	}
}

void Solution::methodStartEndNum(int rowOrCol, int positionInRowOrCol)
{
	const Line* analyzedLine = conditions[rowOrCol][positionInRowOrCol]->getLinePtr();
	int start = conditions[rowOrCol][positionInRowOrCol]->getStart();
	int end = conditions[rowOrCol][positionInRowOrCol]->getEnd();

	std::list<NumberAndBorders>::const_iterator startIter = conditions[rowOrCol][positionInRowOrCol]->getNumInfo().cbegin();
	while (analyzedLine->getCellType(start) != CellType::undefined)
	{
		if (analyzedLine->getCellType(start) == CellType::white) start++;
		else
		{
			start++;		// тк перва€ клетка числа уже закрашена
			for (int count = 0; count <= (*startIter).getNumber() - 1; count++)
			{
				if (start > end)	// условие эквивалентное тому, что строка полностью закрашена
					return;
				else if (count < (*startIter).getNumber() - 1)
				{
					this->setColorWithInformation(rowOrCol, positionInRowOrCol, start++, CellType::black);	// закрашиваем Number-1 клетку
				}
				else		// если count == (*startIter).getNumber() - 1
					this->setColorWithInformation(rowOrCol, positionInRowOrCol, start++, CellType::white);	// и добавл€ем в конце 0
			}
			startIter++;	// переходим к следующему числу
		}
	}

	std::list<NumberAndBorders>::const_reverse_iterator endIter = conditions[rowOrCol][positionInRowOrCol]->getNumInfo().crbegin();
	while (analyzedLine->getCellType(end) != CellType::undefined)
	{
		if (analyzedLine->getCellType(end) == CellType::white) end--;
		else
		{
			end--;		// тк перва€ клетка числа уже закрашена
			for (int count = 0; count <= (*endIter).getNumber() - 1; count++)
			{
				if (start > end)	// условие эквивалентное тому, что строка полностью закрашена
					return;
				else if (count < (*endIter).getNumber() - 1)
				{
					this->setColorWithInformation(rowOrCol, positionInRowOrCol, end--, CellType::black);	// закрашиваем Number-1 клетку
				}
				else		// если count == (*startIter).getNumber() - 1
					this->setColorWithInformation(rowOrCol, positionInRowOrCol, end--, CellType::white);	// и добавл€ем в конце 0
			}
			endIter++;	// переходим к следующему числу
		}
	}
}

void Solution::method1(int rowOrCol, int positionInRowOrCol)
{
	std::cout << "¬ызов method1\n";
}

void Solution::method2(int rowOrCol, int positionInRowOrCol)
{
	std::cout << "¬ызов method2\n";
}

void Solution::setColorWithInformation(int rowOrCol, int positionInRowOrCol, int index, CellType Ctype)
{
	if (rowOrCol == row)
		pict->setColor(positionInRowOrCol, index, Ctype);
	else
		pict->setColor(index, positionInRowOrCol, Ctype);
}
