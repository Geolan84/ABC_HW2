//------------------------------------------------------------------------------
// beast.h - describes beasts.
//------------------------------------------------------------------------------

#ifndef __beast__
#define __beast__
#include "Animal.h"
#include "stdio.h"

enum keyLive {
    DOMESTIC, WILD, GARDEN
};

//------------------------------------------------------------------------------
// beast class.
//------------------------------------------------------------------------------
class Beast : public Animal {
private:
    keyLive k;

public:
    explicit Beast(std::string aName, int aWeight, int aLength);

    void in(FILE *input) override;

    void inRandom() override;

    void out(FILE *output) override;
};

#endif //__beast__
