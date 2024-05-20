﻿#pragma once
#ifndef IMETHOD_NONOGRAM
#define IMETHOD_NONOGRAM
#include <utility>
#include <string>

// forward declaration
class Condition;
class Picture;
enum class CellType;

// интерфес для методов
class IMethod
{
public:
	// функция, реализующая метод, изменяющий изображение. Входные параметры:
	// cond - условие конкретной строки/столбца
	// pict - изображение, в которое будут вноситься изменения
	// posit.first - определяет срока или столбец
	// posit.second - номер строки/столбца
	virtual void realization(const Condition* const cond, Picture* pict, const std::pair<int, int>& posit) const = 0;

	// возвращает название метода
	virtual std::string methodName() const = 0;

	// возвращает описание принципа работы метода
	virtual std::string principleOfMethodWork() const = 0;

	// функция, закрашивающая в Pict posit.first под номером posit.second позиции index цветом cType
	void setColorWithInformation(Picture* pict, const std::pair<int, int>& posit, int index, CellType cType) const;
};

#endif // !IMETHOD_NONOGRAM
