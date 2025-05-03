#pragma once
#include "MyString.h"

class Student
{
	MyString name;
	unsigned fn;
	unsigned course;

public:
	const MyString getName() const;
	unsigned getFN() const;
	unsigned getCourse() const;
	void setCourse(unsigned course);
};

class StudentDB
{
	Student* students;
	size_t capacity;
	size_t size;
	static constexpr unsigned INITIAL_CAPACITY = 8;

	void copyFrom(const StudentDB& other);
	void moveFrom(StudentDB&& other);
	void free();

protected:
	void resize(size_t newCapacity);

public:
	StudentDB();
	StudentDB(const Student* students, size_t size);
	StudentDB(const StudentDB& other);
	StudentDB(StudentDB&& other) noexcept;
	StudentDB& operator=(StudentDB&& other) noexcept;
	StudentDB& operator=(const StudentDB other);
	~StudentDB();

	const Student& getStudent(size_t index) const;
	void setStudents(size_t index, const Student& st);
	void setSize(size_t size);
	size_t getSize() const;

	void addStudent(const Student& other);
	void removeStudent(unsigned fn);
	void findStudent(unsigned fn);
	void display();
};

