#pragma once

namespace constants
{
	constexpr int MAX_POINTS = 100;
}
class GradeReport
{
	int counter;
	int* grades = nullptr;
	char* nameOfReport=nullptr;

public:
	GradeReport()=default;
	GradeReport(const GradeReport& other);
	GradeReport(const char* nameOfReport, int counter, const int* grades);
	GradeReport& operator=(const GradeReport& other);
	~GradeReport();

	void setName(const char* newName);
	void setGradeCount(int count);
	void setGrades(const int* grades, int counter);

	const char* getName() const;
	int getGradesCount() const;
	const int averageGrade() const;

private:
	void copyFrom(const GradeReport& other);
	void free();
};

