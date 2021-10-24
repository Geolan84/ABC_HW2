//------------------------------------------------------------------------------
//  Bird-class methods.
//------------------------------------------------------------------------------

#include "../headers/Bird.h"

Bird::Bird(std::string aName, int aWeight, int aLength) : Animal(aName, aWeight, aLength) {
    isFlight = false;
}

//------------------------------------------------------------------------------
// Output the bird.
//------------------------------------------------------------------------------
void Bird::out(FILE *output) {
    const char *array = name.c_str();
    fprintf(output, "%s%s%s%i%s%s%s%f\n", "Name = ", array,". Weight = ", weight,
            ". It is a bird. Can flight? = ", (isFlight?"yes":"no"), ". Quotient = ", quotient);
}

// Random input.
void Bird::inRandom() {
    isFlight = rand()%2;
}

//------------------------------------------------------------------------------
// Input from a file.
//------------------------------------------------------------------------------
void Bird::in(FILE *input) {
        char flag [100];
        fscanf(input, "%s", flag);
        isFlight = (std::string(flag)=="true");
}
