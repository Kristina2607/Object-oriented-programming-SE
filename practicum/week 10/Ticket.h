#pragma once
#include "MyString.h"

class Ticket
{
	MyString name;
	double price;

public:
	Ticket();
	Ticket(const MyString& name, double price);
	double getPrice()const;
	const MyString& getName() const;
	void print();
};

class StudentTicket:public Ticket
{
	StudentTicket(const MyString& name, double price);
};

class GroupTicket :public Ticket
{
	GroupTicket(const MyString& name, double price);
};
