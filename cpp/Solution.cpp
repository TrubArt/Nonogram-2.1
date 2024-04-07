#include "../headers/Solution.h"
#include "../headers/FileLoader.h"

Solution::Solution(const std::string& fileCondition, const std::string& fileAdditCondit)
{
	FileLoader cond(fileCondition);

	std::vector<int> tmp;

	// получение данных о размере изображения
	tmp = cond.getNumbersSequence();
	int N = tmp[0];
	int M = tmp[1];

	pict = new Picture(N, M);
	conditions[0].resize(N);
	conditions[1].resize(M);

	// получение данных о строках и столбцах
	for (auto& i : conditions[0])
		i = new Condition(M, cond.getNumbersSequence());
	for (auto& i : conditions[1])
		i = new Condition(N, cond.getNumbersSequence());

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
