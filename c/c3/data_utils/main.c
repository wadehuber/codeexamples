#include <stdio.h>
#include "data_utils.h"

int main(void)
{
    double temperatures[] = {72.5, 74.1, 69.8, 81.2, 77.6};
    int size = 5;
    double threshold = 75.0;

    printf("Temperature Data\n");
    printf("----------------\n");
    printf("Average: %.1f\n", average(temperatures, size));
    printf("Minimum: %.1f\n", minimum(temperatures, size));
    printf("Maximum: %.1f\n", maximum(temperatures, size));
    printf("Above %.1f: %d\n",
           threshold,
           count_above(temperatures, size, threshold));

    return 0;
}
