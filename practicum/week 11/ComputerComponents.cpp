#include "ComputerComponents.h"

void ComputerComponent::copyFrom(const ComputerComponent& other)
{
    size_t strLen = strlen(other.label);
    label = new char[strLen + 1];
    strcpy(label, other.label);
}

void ComputerComponent::moveFrom(ComputerComponent&& other)
{
    label = other.label;
    other.label = nullptr;
}

void ComputerComponent::free()
{
    delete[] label;
    label = nullptr;
}

const char* ComputerComponent::getLabel() const
{
    return label;
}

ComputerComponent::ComputerComponent(const char* label)
{
    size_t strLen = strlen(label);
    this->label = new char[strLen + 1];
    strcpy(this->label, label);
}

ComputerComponent::ComputerComponent(const ComputerComponent& other)
{
    copyFrom(other);
}

ComputerComponent::ComputerComponent(ComputerComponent&& other) noexcept
{
    moveFrom(std::move(other));
}

ComputerComponent& ComputerComponent::operator=(const ComputerComponent& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

ComputerComponent& ComputerComponent::operator=(ComputerComponent&& other) noexcept
{
    if (this != &other)
    {
        free();
       moveFrom(std::move(other));
    }
    return *this;
}

void ComputerComponent::output(std::ostream& os) const
{
    os << getLabel() << "," <<price() << std::endl;
}

ComputerComponent::~ComputerComponent()
{
    free();
}
