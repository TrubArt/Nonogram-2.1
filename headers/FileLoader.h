#pragma once
#ifndef FILELOADER_NONOGRAM
#define FILELOADER_NONOGRAM
#include <fstream>
#include <string>
#include <vector>

// �����, ����������� ��� �������� ������� ���������� �� ����� � Picture
class FileLoader
{
	std::ifstream file;	// ����� � ������

public:
	// constructors, destructor, operators

	FileLoader() = delete;
	FileLoader(const std::string& fileName);
	~FileLoader();

	/// <returns>���������� ���� �� ����</returns>
	bool isEmpty() const;

	/// <returns>vector c ������������������� ����� �� ������</returns>
	std::vector<int> getNumbersSequence();

private:
	/// <param name="str">������ ��� ������</param>
	/// <param name="index">������ ������ ������(���������� ��������)</param>
	/// <returns>���� ����� �� ������</returns>
	int getNumber(const std::string& str, int& index);
};
#endif // !FILELOADER_NONOGRAM
