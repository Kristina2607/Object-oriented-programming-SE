#pragma once
#include "IntSet.h"
#include <iostream>

class ArraySet:public IntSet
{
	int* arr;
	size_t size;
	size_t capacity;
	void copyFrom(const ArraySet& other);
	void free();
	void moveFrom(ArraySet&& other);

public:
	~ArraySet() override;
	bool member(int x) const override;
	int get(int index) const override;
	size_t getSize() const override;
	bool insert(int x);
	bool remove(int x);

	ArraySet(int* arr, size_t capacity);
	ArraySet& operator=(const ArraySet& other);
	ArraySet& operator=(ArraySet&& other) noexcept;
	ArraySet(const ArraySet& other);
	ArraySet(ArraySet&& other)  noexcept;
};

