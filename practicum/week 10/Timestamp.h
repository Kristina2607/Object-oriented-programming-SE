#pragma once
#include <iostream>
class Timestamp
{
	unsigned time;

public:
	Timestamp();
	Timestamp(unsigned time);
	void setTime(unsigned time);
	int getTime() const;
	Timestamp& operator+=(int time);
	friend std::istream& operator>>(std::istream& is, const Timestamp& time);
	friend  std::ostream& operator<<(std::ostream& os, const Timestamp& time);
};

class TimestampWithDescription:public Timestamp
{
	char* description;
	void copyFrom(const TimestampWithDescription& other);
	void free();
	void moveFrom(TimestampWithDescription&& other);

public:
	TimestampWithDescription()=default;
	TimestampWithDescription(unsigned time, const char* description);

	const char* getDescription() const;
	void setDescription(const char* description);

	TimestampWithDescription& operator=(TimestampWithDescription&& other);
	TimestampWithDescription(const TimestampWithDescription& other);
	TimestampWithDescription& operator=(const TimestampWithDescription& other);
	TimestampWithDescription(TimestampWithDescription&& other);

	friend std::istream& operator>>(std::istream& is, const TimestampWithDescription& t);
	friend std::ostream& operator<<(std::ostream& os, const TimestampWithDescription& t);
	~TimestampWithDescription();
};