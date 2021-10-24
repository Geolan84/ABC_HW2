//------------------------------------------------------------------------------
// fish.h - describes fish.
//------------------------------------------------------------------------------

#ifndef __fish__
#define __fish__

#include "Animal.h"

// Enum place of living.
enum key {RIVER, SEA, LAKE};

class Fish : public Animal {
 private:
    key k;

 public:
    explicit Fish(std::string aName, int aWeight, int aLength);

    void in(FILE *input) override;

    void inRandom() override;

    void out(FILE *output) override;
};

#endif //__fish__