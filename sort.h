#ifndef SORT_H
#define SORT_H

#include <stddef.h>  /* For size_t */

/* Function prototypes */
void quick_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Struct for doubly linked list node */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

#endif /* SORT_H */

