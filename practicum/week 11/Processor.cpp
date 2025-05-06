#include "Processor.h"

Processor::Processor(const char* label, unsigned cores, unsigned clockSpeed)
    :ComputerComponent(label),cores(cores),clockSpeed(clockSpeed){}

unsigned short Processor::getCores() const
{
    return cores;
}

ComputerComponent* Processor::clone() const
{
    return new Processor (*this);
}

double Processor::price() const
{
    return cores * priceForCore;
}

void Processor::output(std::ostream& os) const
{
    ComputerComponent::output(os);
    os << cores << "," << clockSpeed << std::endl;
}

