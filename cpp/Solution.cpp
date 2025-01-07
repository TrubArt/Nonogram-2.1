#include "../headers/Solution.h"
#include "../headers/FileLoader.h"
#include "../methods/headers/MetStartEndNum.h"
#include "../methods/headers/MetLastColorSet.h"

Solution::Solution(const std::string& fileCondition, const std::string& fileAdditCondit)
{
	// enum для обращения к строкам/столбцам в conditions
	enum LineClassifier { row, col };

	FileLoader cond(fileCondition);

	std::vector<int> tmp;

	// получение данных о размере изображения
	tmp = cond.getNumbersSequence();
	size_t sizeN = tmp[0];
	size_t sizeM = tmp[1];

	pict = new Picture(sizeN, sizeM);
	conditions[row].resize(sizeN);
	conditions[col].resize(sizeM);

	// сначала добавление доп. цветов
	FileLoader f2(fileAdditCondit);
	while (!f2.isEmpty())
	{
		tmp = f2.getNumbersSequence();
		if (!tmp.empty())
		{
			pict->setColor(tmp[0], tmp[1], static_cast<CellType>(tmp[2]));
		}
	}

	// потом получение данных о строках и столбцах
	for (size_t i = 0; i < sizeN; ++i)
	{
		conditions[row][i] = new Condition(sizeM, pict->getPtr(std::make_pair(row, i)), cond.getNumbersSequence());
	}
	for (size_t i = 0; i < sizeM; ++i)
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
	for (size_t i = 0; i < conditions.size(); ++i)
	{
		for (size_t j = 0; j < conditions[i].size(); ++j)
		{
			if (!conditions[i][j]->getIsFullFlag())
			{
				return false;
			}
		}
	}
	return true;
}

void Solution::callingMethods(const std::vector<IMethod*>& methods)
{
	// изображение, с которым будет сравниваться pict для вывода изменений в консоль
	Picture pictDifferences(*pict);

	// данные строк, с которыми будет сравниваться conditions для вывода изменений в консоль
	std::array<std::vector<Condition>, 2> condDif;
	for (size_t i = 0; i < conditions.size(); ++i)
	{
		condDif[i].resize(conditions[i].size());
		for (size_t j = 0; j < conditions[i].size(); ++j)
		{
			condDif[i][j] = *conditions[i][j];
		}
	}

	// цикл с прогоном всех методов
	for (const auto& i : methods)
	{
		// двойной цикл для прохода по всем строкам/столбцам
		for (size_t rowOrCol = 0; rowOrCol < conditions.size(); ++rowOrCol)
		{
			for (size_t positionInRowOrCol = 0; positionInRowOrCol < conditions[rowOrCol].size(); ++positionInRowOrCol)
			{
				if (conditions[rowOrCol][positionInRowOrCol]->getIsFullFlag())		// если строка уже завершена
				{
					continue;
				}

				// вызов определённого метода					
				i->realization(conditions[rowOrCol][positionInRowOrCol], pict, std::make_pair(rowOrCol, positionInRowOrCol));

				// метод по определению числа с края строки
				StartEndNum().realization(conditions[rowOrCol][positionInRowOrCol], pict, std::make_pair(rowOrCol, positionInRowOrCol));

				// изменение данных о строке после цикла
				UpdCondReturnParam updPar = conditions[rowOrCol][positionInRowOrCol]->updateCondition();
				if (updPar != UpdCondReturnParam::lineNotCompleted)	// если строка закончена, то однозначно закрашиваем оставшиеся поля
				{
					LastColorSet().anotrealization(conditions[rowOrCol][positionInRowOrCol], pict, std::make_pair(rowOrCol, positionInRowOrCol), updPar);
				}

			}
		}

		// изменение pictDifferences и condDif текущими значениями pict и conditions

		std::cout << "Изображение после работы " << i->methodName() << ":\n"; //<< this->pictToString() << "\n";
		pict->printToConsoleDifferences(pictDifferences, 4);
		pictDifferences = *pict;

		std::cout << "\nГраницы после работы " << i->methodName() << ":\n"; //<< this->conditionsToString() << "\n";
		this->printToConsoleConditionDifferences(condDif, 4);
		for (size_t i = 0; i < conditions.size(); ++i)
		{
			for (size_t j = 0; j < conditions[i].size(); ++j)
			{
				condDif[i][j] = *conditions[i][j];
			}
		}
	}
}

void Solution::printToConsoleConditionDifferences(const std::array<std::vector<Condition>, 2>& cond, int color) const
{
	for (size_t i = 0; i < conditions.size(); ++i)
	{
		for (size_t j = 0; j < conditions[i].size(); ++j)
		{
			std::cout << i << " " << j << ": ";
			conditions[i][j]->printToConsoleDifferences(cond[i][j], color);
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

	for (size_t i = 0; i < conditions.size(); ++i)
	{
		for (size_t j = 0; j < conditions[i].size(); ++j)
		{
			answer.append(std::to_string(i) + " " + std::to_string(j) + ": ");
			answer.append(conditions[i][j]->toString());
		}
	}

	return answer;
}
