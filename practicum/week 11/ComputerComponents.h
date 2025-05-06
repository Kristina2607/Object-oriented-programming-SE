#pragma once
#include <iostream>

class ComputerComponent
{
	char* label;
	void copyFrom(const ComputerComponent& other);
	void moveFrom(ComputerComponent&& other);
	void free();

public:
	const char* getLabel() const;
	ComputerComponent(const char* label);
	ComputerComponent(const ComputerComponent& other);
	ComputerComponent(ComputerComponent&& other) noexcept;
	ComputerComponent& operator=(const ComputerComponent& other);
	ComputerComponent& operator=(ComputerComponent&& other) noexcept;

	virtual double price() const = 0;
	virtual void output(std::ostream& os) const = 0;
	virtual ComputerComponent* clone() const = 0;
	virtual ~ComputerComponent();
};

