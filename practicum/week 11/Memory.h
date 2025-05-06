#pragma once
#include "ComputerComponents.h"

class Memory:public ComputerComponent
{
	unsigned short capacity;
	unsigned short GBs;
	static constexpr double priceForGB = 89.99;

public:
	unsigned short getGBs() const;
	Memory(const char* label, unsigned short capcity, unsigned short GBs);
	virtual ComputerComponent* clone() const override;
	virtual double price() const override;
	virtual void output(std::ostream& os)const override;
};

