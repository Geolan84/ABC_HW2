#ifndef __container__
#define __container__

#include "Animal.h"

class Container {
 private:
    int currentLen;
    Animal *cont[10000];

 public:
    Container();

    ~Container();

    void in(FILE *input);

    void inRandom(int size);

    void out(FILE *output);

    void ShakerSorting();
};

#endif
