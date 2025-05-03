#include "Student.h"

const MyString Student::getName() const
{
	return name;
}

unsigned Student::getFN() const
{
	return fn;
}

unsigned Student::getCourse() const
{
	return course;
}

void Student::setCourse(unsigned course) 
{
	if (course <= 0 || course >= 5)
	{
		throw std::logic_error("Incorect data");
	}
	this->course = course;
}




void StudentDB::copyFrom(const StudentDB& other)
{
	size = other.size;
	capacity = other.capacity;
	students = new Student[capacity];
	for (int i = 0; i < size; i++)
	{
		students[i] = other.students[i];
	}
}

void StudentDB::moveFrom(StudentDB&& other)
{
	size = other.size;
	capacity = other.capacity;
	students = other.students;
	other.students = nullptr;
}

void StudentDB::resize(size_t newCapacity)
{
	Student* temp = new Student[newCapacity];
	for (int i = 0; i < size; i++)
	{
		temp[i] = students[i];
	}
	delete[]students;
	capacity = newCapacity;
	students = temp;
}

void StudentDB::free()
{
	delete[] students;
	students = nullptr;
	size = 0;
}

StudentDB::StudentDB()
{
	capacity = INITIAL_CAPACITY;
	size = 0;
	students = nullptr;
}

StudentDB::StudentDB(const Student* students, size_t size)
{
	this->size = size;
	this->students = new Student[capacity];
	for (size_t i = 0; i < size; i++)
	{
		this->students[i] = students[i];
	}
}

StudentDB::StudentDB(const StudentDB& other)
{
	copyFrom(other);
}

StudentDB::StudentDB(StudentDB&& other) noexcept
{
	moveFrom(std::move(other));
}

StudentDB& StudentDB::operator=(StudentDB&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return* this;
}

StudentDB& StudentDB::operator=(const StudentDB other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

StudentDB::~StudentDB()
{
	free();
}

const Student& StudentDB::getStudent(size_t index) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (i == index)
		{
			return students[i];
		}
	}
	throw std::invalid_argument("Invalid index");
}

void StudentDB::setStudents(size_t index, const Student& st)
{
	students[index] = st;
}

void StudentDB::setSize(size_t size)
{
	this->size = size;
}

size_t StudentDB::getSize() const
{
	return size;
}

void StudentDB::addStudent(const Student& other)
{
	if (size >= capacity)
	{
		resize(size * 1.5);
	}
	students[size++] = other;
}

void StudentDB::removeStudent(unsigned fn)
{
	for (size_t i = 0; i < size; i++)
	{
		if (students[i].getFN() == fn)
		{
			std::swap(students[i], students[size-1]);
			size--;
		}
	}
}

void StudentDB::findStudent(unsigned fn)
{
	for (size_t i = 0; i < size; i++)
	{
		if (students[i].getFN() == fn)
		{
			std::cout << "The student is found.";
		}
	}
	throw std::invalid_argument("Student with this fn does not exist");
}

void StudentDB::display()
{
	std::cout << size << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		std::cout << students[i].getName() << std::endl
			<< students[i].getFN() << std::endl
			<< students[i].getCourse() << std::endl;
	}
}





