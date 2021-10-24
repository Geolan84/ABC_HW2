#include <cstdlib>
#include <ctime>
#include <cstring>

#include "../headers/Container.h"

void errMessage1() {
    printf( "incorrect command line!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n");

}

int main(int argc, char *argv[]) {
    // начало отсчета времени исполнения
    double timeSpent = 0.0;
    clock_t begin = clock();

    if (argc != 5) {
        errMessage1();
        return 1;
    }

    printf("Start\n");
    Container container = Container();

    if (!strcmp(argv[1], "-f")) {
        FILE *input = fopen(argv[2], "r");
        container.in(input);
        fclose(input);
    } else if (!strcmp(argv[1], "-n")) {
        printf("Random input\n");
        int size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            printf("incorrect number of animals!");
            printf("Set 0 < number <= 10000\n");
            return 3;
        }
        srand(static_cast<unsigned int>(time(0)));
        container.inRandom(size);
    } else {
        errMessage1();
        return 2;
    }

    // Output to first file.
    FILE *output = fopen(argv[3], "w");
    fprintf(output, "%s", "Before sorting: ");
    container.out(output);
    fclose(output);


    // Output to second file.
    container.ShakerSorting();
    FILE *output2 = fopen(argv[4], "w");
    fprintf(output2, "%s", "After sorting: ");
    container.out(output2);
    fclose(output2);

    printf("Stop\n");

    // Check the time of work.
    clock_t end = clock();
    timeSpent = (double) (end - begin);
    printf("Time spent: %f\n", timeSpent / CLOCKS_PER_SEC);
    return 0;
}
