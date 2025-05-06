#pragma once
class IntSet
{

public:
	virtual bool member(int x) const=0;
	virtual int get(int i) const=0;
	virtual size_t getSize() const = 0;
	virtual bool isSubsetOf(const IntSet& set) const;
	virtual bool intersects(const IntSet& set) const;
	virtual ~IntSet() = default;
};

