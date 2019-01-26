#include <string.h>
#include "port.h"

Port::Port(const char* br = "none", const char* st = "none", int b = 0)
    :bottles(b)
{
    brand = strdup(br);
    strncpy(style, st, static_cast<size_t> (19));
}

// Copy constructor
Port::Port(const Port& p)
    : bottles(p.bottles)
{
    brand = strdup(p.brand);
    strncpy(style, p.style, static_cast<size_t> (19));
}

// Copy assignment
Port& Port::operator= (const Port & p)
{
    if(this == &p)
        return *this;

    char* tempName;
    try
    {
        tempName = new char[strlen( p.brand ) + 1];
    }
    catch (std::bad_alloc& ba)
    {
        std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    }

    delete[] brand;
    brand = tempName;
    strcpy(brand, p.brand);
    bottles = p.bottles;
    strncpy(style, p.style, static_cast<size_t> (19));
    return *this;
}

Port& Port::operator+= (int b)
{
    bottles += b;
    return *this;
}

Port& Port::operator-= (int b)
{
    if (bottles < b)
        bottles = 0;
    else
        bottles -= b;
    return *this;
}

void Port::Show() const
{
    std::cout << "Brand: " << brand << "\n"
              << "Style: " << style << "\n"
              << "Bottles: " << bottles << "\n";
}

std::ostream& operator<< (std::ostream& os, const Port& p)
{
    os << p.brand << ", " << p.style << ", " << p.bottles << '\n';
    return os;
}





