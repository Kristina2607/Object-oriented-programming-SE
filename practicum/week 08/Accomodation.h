#pragma once

enum class Type
{
	Apartment,
	Hotel,
	Villa
};

struct Point
{
	int x;
	int y;
};

static int getDistance(const Point& p1, const Point& p2);

class Accomodation
{
	static size_t counter;
	size_t id = 0;
	char* name;
	Type type;
	Point location;
	double price;
	bool isBooked;
	size_t daysToStay;

	void copyFrom(const Accomodation& other);
	void free();

public:
	Accomodation();
	Accomodation(const Accomodation& other);
	Accomodation(const char* name, Type type, Point location, double price, size_t daysToStay);
	Accomodation& operator=(const Accomodation& other);
	~Accomodation();

	void setDaysToStay(size_t daysToStay);
	void setIsBooked(bool isBooked);
	void setPrice(double price);
	void setLocation(Point location);
	void setName(const char* name);
	void setType(Type type);

	const char* getName() const;
	Type getType() const;
	double getPrice()  const;
	size_t getId()  const;
	bool getIsBooked()  const;
	const Point& getLocation() const;

	void reserve(size_t daysToStay);
	void removeReservation();
	double sumForStay();
};

class AirBnb
{
	size_t size;
	size_t capacity;
	Accomodation* accomodations;
	void resize(size_t capacity);
	void copyFrom(const AirBnb& other);
	void free();

public:
	static constexpr size_t initialCapacity = 8;
	static constexpr size_t resizeFactor = 2;

	AirBnb();
	AirBnb(const AirBnb& other);
	AirBnb(const Accomodation* accomodations, size_t size, size_t capacity);
	AirBnb& operator=(const AirBnb& other);
	~AirBnb();

	void addAccomodation(const Accomodation& newAcc);
	void reserve(size_t id, size_t daysToStay);
	void cancelReservation(size_t id);
	double getProfit();
	const Point& getClosestLoc(const Point& location) const;
	void removeAcc(size_t id);

};

