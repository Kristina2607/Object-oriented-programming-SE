#include "Ticket.h"
#include <iostream>

Ticket::Ticket(): price(0), name("") {}

Ticket::Ticket(const MyString& name, double price) : name(name), price(price) {}

double Ticket::getPrice() const
{
    return price;
}

const MyString& Ticket::getName() const
{
    return name;
}

void Ticket::print()
{
    std::cout << name << std::endl<< price;
}

StudentTicket::StudentTicket(const MyString& name, double price) :Ticket(name, price / 2) {}

GroupTicket::GroupTicket(const MyString& name, double price):Ticket (name, (price *0.8)) {}
