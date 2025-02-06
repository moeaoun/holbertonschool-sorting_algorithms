#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using
 *               the Bubble Sort algorithm
 *
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, j;
    int temp;
    int swapped;

    if (array == NULL || size < 2)
        return;

    for (i = 0; i < size - 1; i++)
    {
        swapped = 0;
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                /* Swap the elements */
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = 1;

                print_array(array, size);  /* Print the array after each swap */
            }
        }

        /* If no two elements were swapped in the inner loop, then the array is sorted */
        if (swapped == 0)
            break;
    }
}

