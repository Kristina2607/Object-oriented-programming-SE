#pragma once
#include <iostream>
template <typename T>
class MyStack
{
	T* data;
	size_t size;
	size_t capacity;
	void copyFrom(const MyStack& other);
	void moveFrom(MyStack&& other);
	void free();

public:
	MyStack() = default;
	MyStack(size_t size);
	MyStack(const MyStack& other);
	MyStack(MyStack&& other) noexcept;
	MyStack<T>& operator=(const MyStack& other);
	MyStack<T>& operator= (MyStack && other) noexcept;
	~MyStack();

	void push(const T& elem);
	void push(T&& elem);
	void pop();
	const T& top() const;
	bool isEmpty() const;
	size_t size();
};

template<typename T>
inline bool MyStack<T>::isEmpty() const
{
	return size == 0;
}

template<typename T>
inline size_t MyStack<T>::size()
{
	return size;
}

template<typename T>
inline void MyStack<T>::copyFrom(const MyStack& other)
{
	size = other.size;
	capacity = other.capacity;
	data = new T[capacity];
	for (size_t i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
}

template<typename T>
inline void MyStack<T>::moveFrom(MyStack&& other)
{
	size = other.size;
	capacity = other.capacity;
	data = other.data;
	other.data = nullptr;
}

template<typename T>
inline void MyStack<T>::free()
{
	delete[] data;
	data = nullptr;
}

template<typename T>
inline MyStack<T>::MyStack(size_t size)
{
	this->size = size;
	this->capacity = size;
	data = new T[capacity];
}

template<typename T>
inline MyStack<T>::MyStack(const MyStack& other)
{
	copyFrom(other);
}

template<typename T>
inline MyStack<T>::MyStack(MyStack&& other) noexcept
{
	moveFrom(std::move(other));
}

template<typename T>
inline MyStack<T>& MyStack<T>::operator=(const MyStack& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename T>
inline MyStack<T>& MyStack<T>::operator=(MyStack&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<typename T>
inline MyStack<T>::~MyStack()
{
	free();
}

template<typename T>
inline void MyStack<T>::push(const T& elem)
{
	if (size == capacity)
	{
		resize(capacaity * 2);
	}
	data[size++]=elem;
}

template<typename T>
inline void MyStack<T>::push(T&& elem)
{
	if (size == capacity)
	{
		resize(capacaity * 2);
	}
	data[size++] = std::move(elem);
}

template<typename T>
inline void MyStack<T>::pop()
{
	if (isEmpty())
	{
		throw std::logic_error("The stack is empty.");
	}
	size--;
}

template<typename T>
inline const T& MyStack<T>::top() const
{
	retun data[size - 1];
}
