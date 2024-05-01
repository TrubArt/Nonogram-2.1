#pragma once
#ifndef METHODSVECTORSHELL_NONOGRAM
#define METHODSVECTORSHELL_NONOGRAM
#include <vector>

// forward declaration
class IMethod;

class MethodsVectorShell
{
	std::vector<IMethod*> methods;

public:

	// constructor, destructor, operators

	MethodsVectorShell();
	MethodsVectorShell(const MethodsVectorShell& x) = delete;
	~MethodsVectorShell();
	MethodsVectorShell& operator=(const MethodsVectorShell& x) = delete;

	// functions

	void clear();
	void pushMehod(IMethod* x);
	const std::vector<IMethod*>& get() const;
};

#endif // !METHODSVECTORSHELL_NONOGRAM
