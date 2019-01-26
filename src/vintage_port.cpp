
#include "port.h"
#include "vintage_port.h"
#include <string.h>

VintagePort::VintagePort(const char* br, int b, const char* nn, int y)
    : Port{br, "vintage", b}, year{y}
{
    try
    {
        nickname = new char[strlen( nn ) + 1];
    }
    catch (std::bad_alloc& ba)
    {
        std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    }
    strcpy(nickname, nn);

}

VintagePort::VintagePort(const VintagePort & vp)
    :Port(vp)
{
    try
    {
        nickname = new char[strlen(vp.nickname ) + 1];
    }
    catch (std::bad_alloc& ba)
    {
        std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    }
    strcpy(nickname, vp.nickname);
    year = vp.year;
}
VintagePort & VintagePort::operator=(const VintagePort & vp)
{
    if(this == &vp)
        return *this;

    this->Port::operator=(vp);
    char* tempName;
    try
    {
        tempName = new char[strlen(vp.nickname ) + 1];
    }
    catch (std::bad_alloc& ba)
    {
        std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    }

    delete[] nickname;
    nickname = tempName;
    strcpy(nickname, vp.nickname);
    year = vp.year;
    return *this;
}

void VintagePort::Show() const
{
    std::cout //<< "Brand: " << brand << "\n"
    //<< "Style: " << style << "\n"
    //	<< "Bottles: " << bottles << "\n";
            << "Nickname: " << nickname << "\n"
            << "Year: " << year << "\n";
}

std::ostream& operator<<(std::ostream& os, const VintagePort& vp)
{
    os << vp.nickname << ", " << vp.year << "\n";
    return os;
}
