#include "data_utils.h"

double average(const double values[], int size)
{
    double sum = 0.0;

    for (int i = 0; i < size; i++)
    {
        sum += values[i];
    }

    return sum / size;
}

double minimum(const double values[], int size)
{
    double min = values[0];

    for (int i = 1; i < size; i++)
    {
        if (values[i] < min)
        {
            min = values[i];
        }
    }

    return min;
}

double maximum(const double values[], int size)
{
    double max = values[0];

    for (int i = 1; i < size; i++)
    {
        if (values[i] > max)
        {
            max = values[i];
        }
    }

    return max;
}

int count_above(const double values[], int size, double threshold)
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (values[i] > threshold)
        {
            count++;
        }
    }

    return count;
}
