#pragma once

namespace CONSTANTS
{
	constexpr int MAX_SHIPS = 30;
	constexpr int MAX_SYMBOLS_File = 128;
}
enum class ClassOfShip
{
	battleship,
	battlecruiser
};

class Ship
{
	char* nameOfShip;
	unsigned yearOfDeparture;
	ClassOfShip classOfShip;
	size_t counterOfWeapons;

	void copyFrom(const Ship& other);
	void free();

public:
	Ship() = default;
	Ship(const Ship& other);
	Ship(const char* nameOfShip, const unsigned yearOfDeparture, const ClassOfShip classOfShip, const size_t counterOfWeapons);
	Ship& operator=(const Ship& other);

	void setName(const char* nameOfShip);
	void setYear(const unsigned yearOfDeparture);
	void setClass(const ClassOfShip classOfShip);
	void setCounter(const size_t counterOfWeapons);

	const char* getName() const;
	const unsigned getYear() const;
	const ClassOfShip getClass() const;
	const char* getClassToString(ClassOfShip classOfShip) const;
	const size_t getCounter()  const;

	~Ship();
};

class Navy
{
	char* country;
	Ship ships[CONSTANTS::MAX_SHIPS];
	unsigned counter;

public:
	void addShip(const Ship& other);
	void removeShip(const char* name);
	const Ship& getShipAtPosition(const unsigned position) const;
	int compareCounterOfWeapons(const Navy& other);
	unsigned getShipCounter() const;
};

class NavyHtmlTableGenerator
{
	const Navy& navy;
	char filename [CONSTANTS::MAX_SYMBOLS_File];

public:
	NavyHtmlTableGenerator() = default;
	NavyHtmlTableGenerator(const Navy& navy, const char* filename);
	void saveToHtmlTable();
};
