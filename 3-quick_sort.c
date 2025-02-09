#include <stdio.h>
#include "sort.h"

/**
 * swap - Swap two integers in an array.
 * @array: Array containing the integers.
 * @i: Index of the first element.
 * @j: Index of the second element.
 * @size: Size of the array.
 */
void swap(int *array, int i, int j, size_t size)
{
    int temp;

    if (i != j)
    {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        print_array(array, size);  /* Print after every swap */
    }
}

/**
 * lomuto_partition - Lomuto partition scheme.
 * @array: Array of integers to be sorted.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Size of the array.
 *
 * Return: The index of the pivot element after partitioning.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high]; /* Pivot is always the last element */
    int i = low - 1, j;

    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(array, i, j, size);
        }
    }
    swap(array, i + 1, high, size); /* Place the pivot in its correct position */
    return (i + 1);
}

/**
 * quick_sort_recursive - Recursively sort the array using quick sort.
 * @array: Array to be sorted.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Size of the array.
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot = lomuto_partition(array, low, high, size);

        quick_sort_recursive(array, low, pivot - 1, size);  /* Sort the left part */
        quick_sort_recursive(array, pivot + 1, high, size); /* Sort the right part */
    }
}

/**
 * quick_sort - Sort an array of integers using the Quick sort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, (int)size - 1, size);
}

