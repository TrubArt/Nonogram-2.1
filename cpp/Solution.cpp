#include "../headers/Solution.h"
#include "../headers/FileLoader.h"
#include "../methods/headers/MetStartEndNum.h"
#include "../methods/headers/MetLastColorSet.h"

Solution::Solution(const std::string& fileCondition, const std::string& fileAdditCondit)
{
	// enum для обращения к строкам/столбцам в conditions
	enum lineClassifier { row, col };

	FileLoader cond(fileCondition);

	std::vector<int> tmp;

	// получение данных о размере изображения
	tmp = cond.getNumbersSequence();
	int sizeN = tmp[0];
	int sizeM = tmp[1];

	pict = new Picture(sizeN, sizeM);
	conditions[row].resize(sizeN);
	conditions[col].resize(sizeM);

	// сначала добавление доп. цветов
	FileLoader f2(fileAdditCondit);
	while (!f2.isEmpty())
	{
		tmp = f2.getNumbersSequence();
		if (!tmp.empty())
			pict->setColor(tmp[0], tmp[1], static_cast<CellType>(tmp[2]));
	}

	// потом получение данных о строках и столбцах
	for (int i = 0; i < sizeN; ++i)
	{
		conditions[row][i] = new Condition(sizeM, pict->getPtr(std::make_pair(row, i)), cond.getNumbersSequence());
	}
	for (int i = 0; i < sizeM; ++i)
	{
		conditions[col][i] = new Condition(sizeN, pict->getPtr(std::make_pair(col, i)), cond.getNumbersSequence());
	}

}

Solution::~Solution()
{
	delete pict;

	for (auto& i : conditions)
	{
		for (auto& j : i)
		{
			delete j;
		}
	}
}

Picture Solution::getPicture() const
{
	return *pict;
}

bool Solution::isEndOfWork() const
{
	for (int i = 0; i < static_cast<int>(conditions.size()); ++i)
	{
		for (int j = 0; j < static_cast<int>(conditions[i].size()); ++j)
		{
			if (!conditions[i][j]->getIsFullFlag())
				return false;
		}
	}
	return true;
}

void Solution::callingMethods(const std::vector<IMethod*>& methods)
{
	// цикл с прогоном всех методов
	for (const auto& i : methods)
	{

		std::cout << "Изображение до работы метода\n" << this->pictToString() << "\n";
		std::cout << "Границы до работы метода\n" << this->conditionsToString() << "\n";


		// двойной цикл для прохода по всем строкам/столбцам
		for (int rowOrCol = 0; rowOrCol < static_cast<int>(conditions.size()); ++rowOrCol)
		{
			for (int positionInRowOrCol = 0; positionInRowOrCol < static_cast<int>(conditions[rowOrCol].size()); ++positionInRowOrCol)
			{
				if (!conditions[rowOrCol][positionInRowOrCol]->getIsFullFlag())		// если строка ещё не завершена
				{
					// вызов определённого метода					
					i->realization(conditions[rowOrCol][positionInRowOrCol], pict, std::make_pair(rowOrCol, positionInRowOrCol));

					// метод по определению числа с края строки
					StartEndNum().realization(conditions[rowOrCol][positionInRowOrCol], pict, std::make_pair(rowOrCol, positionInRowOrCol));

					// изменение данных о строке после цикла
					UpdCondReturnParam updPar = conditions[rowOrCol][positionInRowOrCol]->updateCondition();
					if (updPar != UpdCondReturnParam::lineNotCompleted)	// если строка закончена, то однозначно закрашиваем оставшиеся поля
						LastColorSet().anotrealization(conditions[rowOrCol][positionInRowOrCol], pict, std::make_pair(rowOrCol, positionInRowOrCol), updPar);
				}
			}
		}


		std::cout << "Изображение после работы метода:\n" << this->pictToString() << "\n";
		std::cout << "Границы после работы метода:\n" << this->conditionsToString() << "\n";

	}
}

std::string Solution::pictToString() const
{
	return pict->toString();
}

std::string Solution::conditionsToString() const
{
	std::string answer;

	for (int i = 0; i < static_cast<int>(conditions.size()); ++i)
	{
		for (int j = 0; j < static_cast<int>(conditions[i].size()); ++j)
		{
			answer.append(std::to_string(i) + " " + std::to_string(j) + ": ");
			answer.append(conditions[i][j]->toString());
		}
	}

	return answer;
}
