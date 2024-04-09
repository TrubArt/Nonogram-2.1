#include <iostream>
#include <Windows.h>
#include "headers/Solution.h"
#include "headers/Picture.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Solution maintask1("Condition", "Additional color condition");

	int step = 1;
	bool endFlag = false;

	while (!endFlag && !maintask1.isEndOfWork())
	{
		Picture pictureToCompare{ maintask1.getPicture() };


		// работа методов


		// если после работы всех методов нет изменений
		if (pictureToCompare == maintask1.getPicture())
			endFlag = true;

		step++;
	}

	// обработка причины прекращения цикла
	if (endFlag)
		std::cout << "Изображение не закончено, после отработки всех методов:(\n";
	std::cout << maintask1.pictToString();
}
