#include "../headers/Container.h"

Container::Container() : currentLen(0) {
}

Container::~Container() {
    for (int i = 0; i < currentLen; ++i) {
        delete cont[i];
    }
    currentLen = 0;
}

// Function for input animals from file.
void Container::in(FILE *input) {
    while (!feof(input)) {
        if ((cont[currentLen] = Animal::staticIn(input)) != nullptr) {
            ++currentLen;
        }
    }
}

// Function for input animals randomly.
void Container::inRandom(int size) {
    while (currentLen < size) {
        if ((cont[currentLen] = Animal::staticInRandom()) != nullptr) {
            currentLen++;
        }
    }
}

// Output animals.
void Container::out(FILE *output) {
    fprintf(output, "%s%i%s", "Container contains ", currentLen," elements.\n\n");
    for (int i = 0; i < currentLen; i++) {
        fprintf(output, "%i: ", i+1);
        cont[i]->out(output);
    }
}

// Method for sorting animal by quotient.
void Container::ShakerSorting()
{
    int left = 0, right = currentLen - 1;
    int flag = 1;
    while ((left < right) && flag > 0)
    {
        flag = 0;
        for (int i = left; i<right; i++)
        {
            if (cont[i]->GetQuotient()>cont[i + 1]->GetQuotient())
            {
                Animal *temp = cont[i];
                cont[i] = cont[i + 1];
                cont[i + 1] = temp;
                flag = 1;
            }
        }
        --right;
        for (int i = right; i>left; i--)
        {
            if (cont[i - 1]->GetQuotient()>cont[i]->GetQuotient())
            {
                Animal *temp = cont[i];
                cont[i] = cont[i - 1];
                cont[i - 1] = temp;
                flag = 1;
            }
        }
        ++left;
    }
}

