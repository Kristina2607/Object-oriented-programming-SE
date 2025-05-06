#include "ArraySet.h"

void ArraySet::copyFrom(const ArraySet& other)
{
    size = other.size;
    capacity = other.capacity;
    arr = new int[capacity];
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = other.arr[i];
    }
}

void ArraySet::free()
{
    delete[] arr;
    arr = nullptr;
}

void ArraySet::moveFrom(ArraySet&& other)
{
    size = other.size;
    capacity = other.capacity;
    arr = other.arr;
    other.arr = nullptr;
}

ArraySet::~ArraySet()
{
    free();
}

bool ArraySet::member(int x) const
{
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] == x)
        {
            return true;
        }
    }
    return false;
}

int ArraySet::get(int index) const
{
    if (index >= size || index < 0)
    {
        throw std::out_of_range("Out of range");
    }
    return arr[index];
}

size_t ArraySet::getSize() const
{
    return size;
}

bool ArraySet::insert(int x)
{
    if (size >= capacity || member(x))
    {
        return false;
    }
    arr[size++] = x;
    return true;
}

bool ArraySet::remove(int x)
{
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] == x)
        {
            std::swap(arr[i], arr[size - 1]);
            size--;
            return true;
        }
    }
    return false;
}

ArraySet::ArraySet(int* arr, size_t capacity): arr(nullptr), capacity(capacity){}

ArraySet& ArraySet::operator=(const ArraySet& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

ArraySet& ArraySet::operator=(ArraySet&& other) noexcept
{
        if (this != &other)
        {
            free();
            moveFrom(std::move(other));
        }
        return *this;
}

ArraySet::ArraySet(const ArraySet& other)
{
    copyFrom(other);
}

ArraySet::ArraySet(ArraySet&& other)  noexcept
{
    moveFrom(std::move(other));
}


