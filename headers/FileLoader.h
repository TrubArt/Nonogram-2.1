#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// �����, ����������� ��� �������� ������� ���������� �� ����� � Picture
class FileLoader
{
	std::ifstream file;	// ����� � ������

public:
	FileLoader() = default;
	FileLoader(const std::string& fileName);
	~FileLoader();

	/// <returns>���������� ���� �� ����</returns>
	bool isEmpty() const;

	/// <param name="str">������ ��� ������</param>
	/// <param name="i">������ ������ ������(���������� ��������)</param>
	/// <returns>���� ����� �� ������</returns>
	int getNumber(const std::string& str, int& i);

	/// <returns>vector c ������������������� ����� �� ������</returns>
	std::vector<int> getNumbersSequence();
};
