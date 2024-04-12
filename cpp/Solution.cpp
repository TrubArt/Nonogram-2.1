#include "../headers/Solution.h"
#include "../headers/FileLoader.h"
#include "../Constants.h"

Solution::Solution(const std::string& fileCondition, const std::string& fileAdditCondit)
{
	FileLoader cond(fileCondition);

	std::vector<int> tmp;

	// получение данных о размере изображения
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
	for (int i = 0; i < conditions.size(); i++)
		for (int j = 0; j < conditions[i].size(); j++)
			if (!conditions[i][j]->getisFullFlag())
				return false;
	return true;
}

void Solution::callingMethods()
{
	for (int methodNum = 0; methodNum < numberOfMethods; methodNum++)
	{
		for (int rowOrCol = row; rowOrCol < conditions.size(); rowOrCol++)
			for (int positionInRowOrCol = 0; positionInRowOrCol < conditions[rowOrCol].size(); positionInRowOrCol++)
				if (!conditions[rowOrCol][positionInRowOrCol]->getisFullFlag())		// если строка ещё не завершена
				{
					this->switchFunction(methodNum, rowOrCol, positionInRowOrCol);

					// метод по определению числа с края строки


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

	for (int i = 0; i < conditions.size(); i++)
		for (int j = 0; j < conditions[i].size(); j++)
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
		std::cout << "Ошибка Solution::switchFunction. Существует меньше методов, чем указано в Constants.h/numberOfMethods\n";
		break;
	}
}

void Solution::methodLastSet(int rowOrCol, int positionInRowOrCol, updCondReturnParam param)
{

}

void Solution::method1(int rowOrCol, int positionInRowOrCol)
{
	std::cout << "Вызов method1\n";
}

void Solution::method2(int rowOrCol, int positionInRowOrCol)
{
	std::cout << "Вызов method2\n";
}
