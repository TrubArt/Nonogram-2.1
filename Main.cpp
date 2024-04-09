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


		// ������ �������


		// ���� ����� ������ ���� ������� ��� ���������
		if (pictureToCompare == maintask1.getPicture())
			endFlag = true;

		step++;
	}

	// ��������� ������� ����������� �����
	if (endFlag)
		std::cout << "����������� �� ���������, ����� ��������� ���� �������:(\n";
	std::cout << maintask1.pictToString();
}
