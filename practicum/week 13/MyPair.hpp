#pragma once
#include <iostream>
template <typename U, typename V>
class MyPair
{
public:
	U first;
	V second;

	U& getFirst() const;
	V& getSecond() const;
};

template <typename U, typename V>
bool operator== (const MyPair<U, V>& rhs, const MyPair<U, V>& lhs)
{
	if (lhs.getFirst() == rhs.getFirst() && lhs.getSecond() == rhs.getSecond())
	{
		return true;
	}
	return false;
}

template <typename U, typename V>
bool operator!=(const MyPair<U, V>& rhs, const MyPair<U, V>& lhs)
{
	return !(lhs == rhs);
}

template <typename U, typename V>
bool operator<(const MyPair<U, V>& rhs, const MyPair<U, V>& lhs)
{
	if (lhs.getFirst() < rhs.getFirst() && lhs.getSecond() < rhs.getSecond())
	{
		return true;
	}
	return false;
}

template<typename U, typename V>
inline U& MyPair<U, V>::getFirst() const
{
	return first;
}

template<typename U, typename V>
inline V& MyPair<U, V>::getSecond() const
{
	return second;
}