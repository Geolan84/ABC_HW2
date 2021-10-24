//------------------------------------------------------------------------------
// animal.h - describes the base animal class.
//------------------------------------------------------------------------------

#ifndef __animal__
#define __animal__
#include "stdio.h"
#include <string>

class Animal {
 protected:
    int weight;
    int lengthOfName;
    double quotient;
    std::string name;
 public:
    explicit Animal(std::string aName, int aWeight, int lengthOfName);

    virtual ~Animal() = default;

    static Animal *staticIn(FILE *input);

    static Animal *staticInRandom();

    virtual void in(FILE *input) = 0;

    virtual void inRandom() = 0;

    virtual void out(FILE *output) = 0;

    void Quotient();

    double GetQuotient();
};

#endif
