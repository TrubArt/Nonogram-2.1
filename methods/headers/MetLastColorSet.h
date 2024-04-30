#pragma once
#ifndef METHOD_LAST_COLOR_SET
#define METHOD_LAST_COLOR_SET
#include "../Imethod.h"

// forward declaration
enum class updCondReturnParam;

// закрашивает все CellType::undefined в цвет param
class LastColorSet : public Imethod
{
public:
	void realization(const Condition* const cond, Picture* pict, const std::pair<int, int>& posit) const override;
	void anotrealization(const Condition* const cond, Picture* pict, const std::pair<int, int>& posit, updCondReturnParam param) const;
};

#endif // !METHOD_LAST_COLOR_SET
