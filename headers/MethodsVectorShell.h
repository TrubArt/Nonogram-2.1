#pragma once
#ifndef METHODSVECTORSHELL_NONOGRAM
#define METHODSVECTORSHELL_NONOGRAM
#include <vector>

// forward declaration
class Imethod;

class MethodsVectorShell
{
	std::vector<Imethod*> methods;

public:

	// constructor, destructor, operators

	MethodsVectorShell();
	MethodsVectorShell(const MethodsVectorShell& x) = delete;
	~MethodsVectorShell();
	MethodsVectorShell& operator=(const MethodsVectorShell& x) = delete;

	// functions

	void clear();
	void pushMehod(Imethod* x);
	const std::vector<Imethod*>& get() const;
};

#endif // !METHODSVECTORSHELL_NONOGRAM
