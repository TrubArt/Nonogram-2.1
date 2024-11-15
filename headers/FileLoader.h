﻿#pragma once
#ifndef FILELOADER_NONOGRAM
#define FILELOADER_NONOGRAM
#include <fstream>
#include <string>
#include <vector>

// класс, необходимый для загрузки условия нонограммы из файла в Picture
class FileLoader
{
	std::ifstream file;	// поток с файлом

public:
	// ctors, dtor, operators

	FileLoader() = delete;
	FileLoader(const std::string& fileName);
	~FileLoader();

	/// <returns>Возвращает пуст ли файл</returns>
	bool isEmpty() const;

	/// <returns>vector c последовательностью чисел из строки</returns>
	std::vector<int> getNumbersSequence();

private:
	/// <param name="str">строка для поиска</param>
	/// <param name="index">индекс начала поиска(изменяется функцией)</param>
	/// <returns>одно число из строки</returns>
	int getNumber(const std::string& str, size_t& index) const;
};
#endif // !FILELOADER_NONOGRAM
