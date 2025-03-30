#include "Ship.h"
#include <cstring>
#include <fstream>
#pragma warning (disable : 4996)

void Ship::copyFrom(const Ship& other)
{
	size_t strLen = strlen(other.nameOfShip);
	nameOfShip = new char[strLen + 1] {};
	strcpy(nameOfShip, other.nameOfShip);
	yearOfDeparture = other.yearOfDeparture;
	counterOfWeapons = other.counterOfWeapons;
    classOfShip = other.classOfShip;
}

void Ship::free()
{
	delete[] nameOfShip;
}

Ship::Ship():nameOfShip(nullptr),yearOfDeparture(0),counterOfWeapons(0){};

Ship::Ship(const Ship& other)
{
	copyFrom(other);
}

Ship::Ship(const char* nameOfShip, const unsigned yearOfDeparture, const ClassOfShip classOfShip, const size_t counterOfWeapons)
{
	setName(nameOfShip);
	setYear(yearOfDeparture);
	setClass(classOfShip);
	setCounter(counterOfWeapons);
}

void Ship::setName(const char* newName)
{
	if (!newName || nameOfShip == newName)
	{
		return;
	}
	delete[] nameOfShip;
	size_t strLen = strlen(newName);
	nameOfShip = new char[strLen + 1];
	strcpy(nameOfShip, newName);
}

void Ship::setClass(const ClassOfShip classOfShip)
{
	this->classOfShip = classOfShip;
}

void Ship::setCounter(const size_t counterOfWeapons)
{
	this->counterOfWeapons=counterOfWeapons;
}

void Ship::setYear(const unsigned yearOfDeparture)
{
	this->yearOfDeparture = yearOfDeparture;
}

const char* Ship::getName() const
{
	return nameOfShip;
}

const unsigned Ship::getYear() const
{
	return yearOfDeparture;
}

const ClassOfShip Ship::getClass() const
{
	return classOfShip;
}

const char* Ship::getClassToString(ClassOfShip classOfShip) const
{
	switch (classOfShip)
	{
	case ClassOfShip::battlecruiser:return "battlecruiser"; break;
	case ClassOfShip::battleship: return "battleship"; break;
	default: return "Invalid";
	}
}

const size_t Ship::getCounter() const
{
	return counterOfWeapons;
}

Ship& Ship::operator= (const Ship& other)
{
	if (this != &other)
	{
		copyFrom(other);
		free();
	}
	return *this;
}

void Navy::addShip(const Ship& other) 
{
	if (counter >= CONSTANTS::MAX_SHIPS)
	{
		return;
	}
	ships[counter++]=other;
}

void Navy::removeShip(const char* nameOfShip)
{
	if (!nameOfShip)
	{
		return;
	}
	for (unsigned i = 0; i < counter; i++)
	{
		if (strcmp(ships[i].getName(), nameOfShip)==0)
		{
			for (int j = i; j < counter-1; j++)
			{
				ships[j] = ships[j+1];
			}
			counter--;
			return;
		}
	}
}

const Ship& Navy::getShipAtPosition(const unsigned position) const
{
	if (position >= counter)
	{
		return {};
	}
	return ships[position];
}

unsigned Navy::getShipCounter() const
{
	return counter;
}

int Navy::compareCounterOfWeapons(const Navy& other)
{
	int sumOfWeaponsOther = 0;
	int sumOfWeaponsThis = 0;
	for (int i = 0; i < counter; i++)
	{
		sumOfWeaponsThis += this->ships[i].getCounter();
	}
	for (int j = 0; j < other.counter; j++)
	{
		sumOfWeaponsOther += other.ships[j].getCounter();
	}
	if (sumOfWeaponsOther == sumOfWeaponsThis)
	{
		return 0;
	}
	else if (sumOfWeaponsOther > sumOfWeaponsThis)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

Ship::~Ship()
{
	free();
}

NavyHtmlTableGenerator::NavyHtmlTableGenerator(const Navy& navy, const char* filename): navy(navy)
{
	if (!filename)
	{
		return;
	}
	if (strlen(filename) > 128)
	{
		return;
	}
	strcpy(this->filename, filename);
	this->filename[CONSTANTS::MAX_SYMBOLS_File] = '\0';
}

void NavyHtmlTableGenerator::saveToHtmlTable()
{
	std::ofstream ofs(filename);
	if (!ofs.is_open())
	{
		return;
	}
	ofs << "<table>\n";
	ofs << "  <tr>\n";
	ofs << "    <th>Name</th>\n";
	ofs << "    <th>Launch Year</th>\n";
	ofs << "    <th>Class</th>\n";
	ofs << "    <th>NumGuns</th>\n";
	ofs << "  </tr>\n";

	for (unsigned i = 0; i < navy.getShipCounter(); i++)
	{
		const Ship& currShip = navy.getShipAtPosition(i);
		ofs << "  <tr>\n";
		ofs << "    <td>" << currShip.getName() << "</td>\n";
		ofs << "    <td>" << currShip.getYear() << "</td>\n";
		ofs << "    <td>" << currShip.getClassToString(currShip.getClass()) << "</td>\n";
		ofs << "    <td>" << currShip.getCounter() << "</td>\n";
		ofs << "  </tr>\n";
	}
	ofs << "/table\n";
	ofs.close();
}
