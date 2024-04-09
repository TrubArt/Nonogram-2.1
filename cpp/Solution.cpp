#include "../headers/Solution.h"
#include "../headers/FileLoader.h"

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
			pict->colorSet(tmp[0], tmp[1], static_cast<CellType>(tmp[2]));
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
		for (int j = 0; j < conditions[0].size(); j++)
			if (!conditions[i][j]->getisFullFlag())
				return false;
	return true;
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
