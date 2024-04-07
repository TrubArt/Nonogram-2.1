#pragma once
#include <fstream>
#include <string>
#include <vector>

// класс, необходимый для загрузки условия нонограммы из файла в Picture
class FileLoader
{
	std::ifstream file;	// поток с файлом

public:
	FileLoader(const std::string& fileName);
	~FileLoader();

	/// <returns>Возвращает пуст ли файл</returns>
	bool isEmpty() const;

	/// <returns>vector c последовательностью чисел из строки</returns>
	std::vector<int> getNumbersSequence();

private:
	/// <param name="str">строка для поиска</param>
	/// <param name="i">индекс начала поиска(изменяется функцией)</param>
	/// <returns>одно число из строки</returns>
	int getNumber(const std::string& str, int& i);
};
