#include "../headers/FileLoader.h"
#include <iostream>

FileLoader::FileLoader(const std::string& fileName)
{
	file.open(fileName + ".txt");
	if (!file.is_open())
	{
		std::cerr << "���� � ������� �� ������!\n";
		std::exit(1);
	}
}

FileLoader::~FileLoader()
{
	file.close();
}

bool FileLoader::isEmpty() const
{
	return file.eof();
}

int FileLoader::getNumber(const std::string& str, int& index)
{
	std::string tmp;
	while (str[index] != ' ' && index < str.length())
		tmp.push_back(str[index++]);
	return std::stoi(tmp);
}

std::vector<int> FileLoader::getNumbersSequence()
{
	std::string str;
	do								// ������� ������ �������
	{
		std::getline(file, str);
	} while (str.empty() && !isEmpty());

	std::vector<int> tmpvec;		// ������ � �������

	for (int i = 0; i < str.length(); i++)
		if (str[i] != ' ')
			tmpvec.push_back(getNumber(str, i));

	return tmpvec;
}
