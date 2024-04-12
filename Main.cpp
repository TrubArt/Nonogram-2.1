#include <iostream>
#include <Windows.h>
#include "headers/Solution.h"
#include "headers/Picture.h"

bool nonogramSolution(Solution& maintask)
{
	int step = 1;
	bool endFlag = false;

	while (!endFlag && !maintask.isEndOfWork())
	{
		Picture pictureToCompare{ maintask.getPicture() };

		// ������ �������
		maintask.callingMethods();

		// ���� ����� ������ ������� ��� ���������
		if (pictureToCompare == maintask.getPicture())
			endFlag = true;

		step++;
	}

	return endFlag;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Solution maintask1("Condition", "Additional color condition");

	bool endFlag = nonogramSolution(maintask1);

	// ��������� ������� ����������� �����
	if (endFlag)
		std::cout << "����������� �� ��������� ����� ��������� ���� �������:(\n";
	std::cout << maintask1.pictToString();
}
