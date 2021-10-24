//------------------------------------------------------------------------------
// bird.h - describes the bird.
//------------------------------------------------------------------------------

#ifndef __bird__
#define __bird__

#include <stdio.h>
#include "Animal.h"

class Bird : public Animal {
 private:
    bool isFlight;

 public:
    explicit Bird(std::string aName, int aWeight, int aLenght);

    void out(FILE *output) override;

    void inRandom() override;

    void in(FILE *input) override;
};

#endif //__bird__
