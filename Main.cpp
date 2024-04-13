#include <iostream>
#include <Windows.h>
#include "headers/Solution.h"
#include "headers/Picture.h"

bool nonogramSolution(Solution& maintask)
{
	int step = 1;
	bool noChangesAfterCycle = false;

	while (!noChangesAfterCycle && !maintask.isEndOfWork())
	{
		Picture pictureToCompare{ maintask.getPicture() };

		// ������ �������
		maintask.callingMethods();

		// ���� ����� ������ ������� ��� ���������
		if (pictureToCompare == maintask.getPicture())
			noChangesAfterCycle = true;

		step++;
	}

	return noChangesAfterCycle;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Solution maintask1("Condition", "Additional color condition");

	std::cout << "����������� �� �������:\n";
	std::cout << maintask1.getPicture();

	bool earlyCycleOut = nonogramSolution(maintask1);

	// ��������� ������� ����������� �����
	if (earlyCycleOut)
		std::cout << "\n����������� �� ��������� ����� ��������� ���� �������:(\n";

	std::cout << "����������� ����� ��������� �������:\n";
	std::cout << maintask1.getPicture();
}
