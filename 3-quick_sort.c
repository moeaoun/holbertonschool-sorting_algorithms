#include "sort.h"
#include <stdio.h>

/**
 * lomuto_partition - Lomuto partition scheme to find the correct position
 *                    of the pivot element and reorder the array.
 *
 * @array: Array to be partitioned.
 * @low: Starting index of the array to partition.
 * @high: Ending index of the array to partition.
 *
 * Return: The index of the pivot element after partitioning.
 */
int lomuto_partition(int *array, int low, int high)
{
    int pivot = array[high];  /* Pivot is the last element */
    int i = low - 1;  /* Index of smaller element */

    for (int j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            /* Swap array[i] and array[j] */
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;

            print_array(array, high + 1);  /* Print after swap */
        }
    }

    /* Swap array[i + 1] and array[high] (pivot) */
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    print_array(array, high + 1);  /* Print after swap */
    
    return (i + 1);
}

/**
 * quick_sort_recursive - Recursively applies quick_sort to subarrays.
 *
 * @array: Array to be sorted.
 * @low: Starting index of the array to sort.
 * @high: Ending index of the array to sort.
 */
void quick_sort_recursive(int *array, int low, int high)
{
    if (low < high)
    {
        /* Partition the array and get the pivot index */
        int pivot_index = lomuto_partition(array, low, high);

        /* Recursively sort the subarrays */
        quick_sort_recursive(array, low, pivot_index - 1);
        quick_sort_recursive(array, pivot_index + 1, high);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick
 *              Sort algorithm and Lomuto partition scheme.
 *
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1);
}

