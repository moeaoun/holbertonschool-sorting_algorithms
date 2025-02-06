#include <stdio.h>
#include "sort.h"  /* Include the header file for the function prototypes */

/* Main function */
int main(void) {
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);  /* Print the initial array */
    printf("\n");
    quick_sort(array, n);  /* Sort the array using quick_sort */
    printf("\n");
    print_array(array, n);  /* Print the sorted array */
    return 0;
}

