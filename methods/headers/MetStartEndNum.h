﻿#pragma once
#ifndef METHOD_STARTENDNUM_NONOGRAM
#define METHOD_STARTENDNUM_NONOGRAM
#include "../IMethod.h"

// если start || end == CellType::black, то однозначно закрашивает клетки принадлежащие первому/последнему числу
class StartEndNum : public IMethod
{
public:
	void realization(const Condition* const cond, Picture* pict, const std::pair<int, int>& posit) const override;
	virtual std::string methodName() const override;
	virtual std::string principleOfMethodWork() const override;
};

#endif // !METHOD_STARTENDNUM_NONOGRAM
