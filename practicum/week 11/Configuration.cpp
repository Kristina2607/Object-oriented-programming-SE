#include "Configuration.h"

void Configuration::insert(ComputerComponent* component)
{
    if (!component)
    {
        throw std::invalid_argument("Invalid argument");
    }
    components[size++] = component;
}

double Configuration::price() const
{
    double total = 0;
    for (size_t i = 0; i < size; i++)
    {
        total += components[i]->price();
    }
}

size_t Configuration::getSize() const
{
    size_t counter;
    for (size_t i = 0; i < size; i++)
    {
        counter++;
    }
    return counter;
}

ComputerComponent* Configuration::create_Component()
{
    std::cout << "p-processor, m-memory"<<std::endl;
    char choice;
    std::cin >> choice;
    switch (choice)
    {
    case 'm': return createMemory();
    case 'p': return createProcessor();
    default: return nullptr;
    }
}

Memory* Configuration::createMemory()
{
    unsigned short GBs = 0;
    unsigned short capacity = 0;
    MyString name;
    std::cin >> name>> GBs >> capacity;
    return new Memory(name.c_str(), GBs, capacity);
}

Processor* Configuration::createProcessor()
{
    unsigned short cores = 0;
    unsigned short clockSpeed = 0;
    MyString name;
    std::cin >> name >> cores >> clockSpeed;
    return new Processor(name.c_str(), cores, clockSpeed);
}

const ComputerComponent* Configuration::operator[](size_t index) const
{
    if (index >= size)
    {
        throw std::invalid_argument("Invalid argument");
    }
    return components[index];
}

std::ostream& operator<<(std::ostream& os, const Configuration& config)
{
    for (size_t i = 0; i < config.size; i++)
    {
        config.components[i]->output(os);
    }
    os << config.price();
    return os;
}
