#pragma once
#include "IntSet.h"
#include<iostream>

class IntRange:public IntSet
{
	int min;
	int max;

public:
	IntRange(int x, int y);
	bool member(int x) const override;
	int get(int index)const override;
	size_t getSize() const override;

};

