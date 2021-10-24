//------------------------------------------------------------------------------
// beast.cpp - contains operations for beasts.
//------------------------------------------------------------------------------

#include "../headers/Beast.h"

Beast::Beast(std::string aName, int aWeight, int aLength) : Animal(aName, aWeight, aLength) {
    k = DOMESTIC;
}

//------------------------------------------------------------------------------
// Output the beast.
//------------------------------------------------------------------------------
void Beast::out(FILE *output) {
    const char *array = name.c_str();
    fprintf(output, "%s%s%s%i%s%s%s%f\n", "Name = ", array,". Weight = ", weight,
            ". It is a beast. It is ", (k==0?"domestic.":(k==1?"wild.":"garden.")),
            " Quotient = ", quotient);
}

//------------------------------------------------------------------------------
// Input from a file.
//------------------------------------------------------------------------------
void Beast::in(FILE *input) {
    int choose;
    fscanf(input, "%i", &choose);
    switch(choose) {
        case 1:
            k = DOMESTIC;
            break;
        case 2:
            k = WILD;
            break;
        case 3:
            k = GARDEN;
            break;
        default:
            return;
    }
}
//------------------------------------------------------------------------------
// Random input.
//------------------------------------------------------------------------------
void Beast::inRandom() {
    int choose = rand() % 3;
    switch(choose) {
        case 0:
            k = DOMESTIC;
            break;
        case 1:
            k = WILD;
            break;
        case 2:
            k = GARDEN;
            break;
        default:
            return;
    }
}
