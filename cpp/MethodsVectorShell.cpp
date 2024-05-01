#include "../headers/MethodsVectorShell.h"

#include "../methods/headers/MetUnambiguousBlack.h"

MethodsVectorShell::MethodsVectorShell()
{
	methods.push_back(new UnambiguousBlack());
}

//MethodsVectorShell::MethodsVectorShell(const MethodsVectorShell& x)
//{
//	for (int i = 0; i < static_cast<int>(x.methods.size()); i++)
//	{
//		methods[i] = new IMethod(x.methods[i]);
//	}
//}

MethodsVectorShell::~MethodsVectorShell()
{
	for (auto& i : methods)
		delete i;
}

//MethodsVectorShell& MethodsVectorShell::operator=(const MethodsVectorShell& x)
//{
//
//}

void MethodsVectorShell::clear()
{
	methods.clear();
}

void MethodsVectorShell::pushMehod(IMethod* x)
{
	methods.push_back(x);
}

const std::vector<IMethod*>& MethodsVectorShell::get() const
{
	return methods;
}