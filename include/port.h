
#ifndef PORT_H
#define PORT_H

#include <string.h>
#include <iostream>

class Port
{
private:
   char* brand;
   char style[20]; // e.g. tawny, ruby, vintage
   int bottles;

public:
//  constructors
    Port(const char* br, const char* st, int b);
    Port(const Port& p);
    virtual ~Port() { delete [] brand; }

// operators
    Port& operator= (const Port & p);
    Port& operator+= (int b) ; // adds b to bottles
    Port& operator-= (int b); // subtracts b from bottles, if possible

//  accessors
    int BottleCount() const { return bottles; }
    virtual void Show() const;

//  friend functions
    friend std::ostream& operator<< (std::ostream& os, const Port& p);
};
#endif
