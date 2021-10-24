//------------------------------------------------------------------------------
// fish.cpp - contains operations for fishes.
//------------------------------------------------------------------------------

#include "../headers/Fish.h"

Fish::Fish(std::string aName, int aWeight, int aLength) : Animal(aName, aWeight, aLength) {

}

//------------------------------------------------------------------------------
// Output the fish.
//------------------------------------------------------------------------------
void Fish::out(FILE *output) {
    const char *array = name.c_str();
    fprintf(output, "%s%s%s%i%s%s%s%f\n", "Name = ", array,". Weight = ", weight,
            ". It is a fish. It lives in ", (k==0?"river":(k==1?"sea":"lake")),
            ". Quotient = ", quotient);
}

//------------------------------------------------------------------------------
// Input from a file.
//------------------------------------------------------------------------------
void Fish::in(FILE *input) {
    int a;
    fscanf(input, "%i", &a);
    switch(a) {
        case 1:
            k = RIVER;
            break;
        case 2:
            k = SEA;
            break;
        case 3:
            k = LAKE;
            break;
        default:
            return;
    }
}
//------------------------------------------------------------------------------
// Random input.
//------------------------------------------------------------------------------
void Fish::inRandom() {
    int a = rand() % 3 + 1;
    switch(a) {
        case 1:
            k = RIVER;
            break;
        case 2:
            k = SEA;
            break;
        case 3:
            k = LAKE;
            break;
        default:
            return;
    }
}
