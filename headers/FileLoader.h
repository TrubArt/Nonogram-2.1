#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// класс, необходимый для загрузки условия нонограммы из файла в Picture
class FileLoader
{
	std::ifstream file;	// поток с файлом

public:
	FileLoader() = default;
	FileLoader(const std::string& fileName);
	~FileLoader();

	/// <returns>Возвращает пуст ли файл</returns>
	bool isEmpty() const;

	/// <param name="str">строка для поиска</param>
	/// <param name="i">индекс начала поиска(изменяется функцией)</param>
	/// <returns>одно число из строки</returns>
	int getNumber(const std::string& str, int& i);

	/// <returns>vector c последовательностью чисел из строки</returns>
	std::vector<int> getNumbersSequence();
};
