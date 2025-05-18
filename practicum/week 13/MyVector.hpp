#pragma once
#include <iostream>
template <typename T>
class MyVector
{
private:
	T* data;
	size_t size;
	size_t capacity;
	static constexpr Initial_Capacity = 8;
	void copyFrom(const MyVector& other);
	void moveFrom(MyVector&& other);
	void free();
	void resize(size_t newCapacity);

public:
	MyVector();
	MyVector(size_t n);
	MyVector(size_t n, const T& elem);
	MyVector(const MyVector<T>& other);
	MyVector(MyVector<T>&& other) noexcept;
	MyVector<T>& operator=(const MyVector<T>& other);
	MyVector<T>& operator=(MyVector<T>&& other) noexcept;
	~MyVector();

	void push_back(const T& elem);
	void push_back(T&& elem);
	void pop_back();
	void insert(size_t index, const T& elem);
	void insert(size_t index, T&& elem);
	void erase(size_t index);

	MyVector<T>& operator[](size_t index);
	MyVector<T>& operator[](size_t index) const;

	void shrink_to_fit();
	void clear();
	T& front();
	const T& front() const;
	T& back();
	const T& back() const;
	bool isEmpty() const;
	size_t getSize() const;
	size_t getCapacity() const;
};

template<typename T>
inline void MyVector<T>::copyFrom(const MyVector& other)
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
inline void MyVector<T>::moveFrom(MyVector&& other)
{
	capacity = other.capacity;
	size = other.size;
	data = other.data;

	other.data = nullptr;
	other.size = other.capacity = 0;
}

template<typename T>
inline void MyVector<T>::free()
{
	delete[] data;
	data = nullptr;
}

template<typename T>
inline void MyVector<T>::resize(size_t newCapacity)
{
	T* temp = new T[newCapacity];
	for (int i = 0; i < size; i++)
	{
		temp[i] = std::move(data[i]);  //temp[i]=data[i];
	}
	delete data[];
	data = temp;
	capacity = newCapacity;
}

template<typename T>
inline MyVector<T>::MyVector()
{
	capacity = Initial_Capacity;
	size = 0;
	data = new T[capacity];
}

template<typename T>
inline MyVector<T>::MyVector(size_t n)
{
	size = capacity = n;
	data = new T[capacity] {};
}

template<typename T>
inline MyVector<T>::MyVector(size_t n, const T& elem)
{
	size = capacity = n;
	data = new T[capacity];
	for (size_t i = 0; i < n; i++)
	{
		data[i] = elem;
	}
}

template<typename T>
inline MyVector<T>::MyVector(const MyVector& other)
{
	copyFrom(other);
}


template<typename T>
inline MyVector<T>::MyVector(MyVector&& other) noexcept
{
	moveFrom(std::move(other));
}

template<typename T>
inline MyVector<T>& MyVector<T>::operator=(const MyVector& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename T>
inline MyVector<T>& MyVector<T>::operator=(MyVector&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other);
	}
	return *this;
}

template<typename T>
inline MyVector<T>::~MyVector()
{
	free();
}

template<typename T>
inline void MyVector<T>::push_back(const T& elem)
{
	if (size == capacity)
	{
		resize(capacity * 2);
	}
	data[size++] = elem;
}

template<typename T>
inline void MyVector<T>::push_back(T&& elem)
{
	if (size == capacity)
	{
		resize(capacity * 2);
	}
	data[size++] = std::move(elem);
}

template<typename T>
inline void MyVector<T>::pop_back()
{
	if (isEmpty())
	{
		throw std::logic_error("The array is empty");
	}
	size--;
}

template<typename T>
inline void MyVector<T>::insert(size_t index, const T& elem)
{
	if (index > size)
	{
		throw std::invalid_argument("Invalid index");
	}
	if (size == capacity)
	{
		resize(capacity * 2);
	}
	for (size_t j = size; j > index; j--)
	{
		data[j] = std::move(data[j - 1]);
	}
	data[index] = elem;
	size++;
}

template<typename T>
inline void MyVector<T>::insert(size_t index, T&& elem)
{
	if (index > size)
	{
		throw std::invalid_argument("Invalid index");
	}
	if (size == capacity)
	{
		resize(capacity * 2);
	}
	for (size_t i = size; i >index; i--)
	{
		data[i] = std::move(data[i - 1]);
	}
	data[index] = elem;
	size++;
}

template<typename T>
inline void MyVector<T>::erase(size_t index)
{
	for (size_t j = i; j < size-1; j++)
	{
		data[j] = data[j + 1];
	}
	size--;
}

template<typename T>
inline MyVector<T>& MyVector<T>::operator[](size_t index)
{
	return data[index];
}

template<typename T>
inline MyVector<T>& MyVector<T>::operator[](size_t index) const
{
	return data[index];
}

template<typename T>
inline void MyVector<T>::shrink_to_fit()
{
	resize(size);
}

template<typename T>
inline void MyVector<T>::clear()
{
	size = 0;
}

template<typename T>
inline T& MyVector<T>::front()
{
	return data[0];
}

template<typename T>
inline const T& MyVector<T>::front() const
{
	return data[0];
}

template<typename T>
inline T& MyVector<T>::back()
{
	return data[size-1];
}

template<typename T>
inline const T& MyVector<T>::back() const
{
	return data[size-1];
}

template<typename T>
inline bool MyVector<T>::isEmpty() const
{
	return size == 0;
}

template<typename T>
inline size_t MyVector<T>::getSize() const
{
	return size;
}

template<typename T>
inline size_t MyVector<T>::getCapacity() const
{
	return capacity;
}