#pragma once
#ifndef METHOD_LAST_COLOR_SET
#define METHOD_LAST_COLOR_SET
#include "../IMethod.h"

// forward declaration
enum class UpdCondReturnParam;

// закрашивает все CellType::undefined в цвет param
class LastColorSet : public IMethod
{
public:
	void realization(const Condition* const cond, Picture* pict, const std::pair<int, int>& posit) const override;
	std::string methodName() const override;
	std::string principleOfMethodWork() const override;
	void anotrealization(const Condition* const cond, Picture* pict, const std::pair<int, int>& posit, UpdCondReturnParam param) const;
};

#endif // !METHOD_LAST_COLOR_SET
