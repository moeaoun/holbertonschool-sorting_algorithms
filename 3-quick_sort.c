#include <stddef.h>  /* Include the correct header for size_t */
#include "sort.h"    /* Include the header file for function prototypes */

/* Function to perform Lomuto partition scheme */
static void lomuto_partition(int *array, size_t low, size_t high, size_t size) {
    int temp;
    int pivot = array[high];  /* pivot is always the last element */
    size_t i = low - 1;
    size_t j;

    for (j = low; j < high; j++) {  /* j is now size_t */
        if (array[j] <= pivot) {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            print_array(array, size);  /* Print the array after swap */
        }
    }

    /* Swap pivot element */
    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    print_array(array, size);  /* Print the array after pivot swap */
}

/* Main quick_sort function */
void quick_sort(int *array, size_t size) {
    if (array == NULL || size < 2)
        return;

    lomuto_partition(array, 0, size - 1, size);
}

