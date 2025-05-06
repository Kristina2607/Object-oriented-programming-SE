#pragma once
#include "ComputerComponents.h"

class Processor: public ComputerComponent
{
	unsigned short cores;
	unsigned short clockSpeed;
	static constexpr double priceForCore = 29.99;
public:
	Processor(const char* label, unsigned cores, unsigned clockSpeed);
	unsigned short getCores() const;
	virtual ComputerComponent* clone() const override;
	virtual double price() const override;
	virtual void output(std::ostream& os) const override;
};

