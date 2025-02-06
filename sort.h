/* sort.h */
#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/* Define the doubly linked list node */
typedef struct listint_s
{
    int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
#endif /* SORT_H */

