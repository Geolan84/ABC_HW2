//------------------------------------------------------------------------------
// animal.cpp - contains operations for creation and processing objects.
//------------------------------------------------------------------------------

#include "../headers/Animal.h"
#include "../headers/Fish.h"
#include "../headers/Beast.h"
#include "../headers/Bird.h"

Animal::Animal(std::string aName, int aWeight, int aLength) {
    name = aName;
    weight = aWeight;
    lengthOfName = aLength;
    Quotient();
}

// Input from a file.
Animal *Animal::staticIn(FILE *input) {
    int type;
    fscanf(input, "%i", &type);
    char charName [100];
    fscanf(input, "%s", &charName);
    int weight;
    fscanf(input, "%i", &weight);
    std::string name(charName);
    Animal *result = nullptr;
    switch (type) {
        case 1:
            result = new Bird(name, weight, name.length());
            break;
        case 2:
            result = new Fish(name, weight, name.length());
            break;
        case 3:
            result = new Beast(name, weight, name.length());
            break;
        default:
            break;
    }
    result->in(input);
    return result;
}

// Random input.
Animal *Animal::staticInRandom() {
    int type = rand()%3+1;
    int weight = rand()+1;
    Animal *result = nullptr;
    switch (type) {
        case 1:
            result = new Bird("Bird", weight, 4);
            break;
        case 2:
            result = new Fish("Fish", weight, 4);
            break;
        case 3:
            result = new Beast("Beast", weight, 5);
            break;
        default:
            break;
    }
    result->inRandom();
    return result;
}

// Method for calculating quotient.
void Animal::Quotient() {
    int sum = 0;
    for(int i=0; i<lengthOfName; ++i){
        sum += name[i];
    }
    quotient = (double)sum/weight;
}
double Animal::GetQuotient() {
    return quotient;
}
