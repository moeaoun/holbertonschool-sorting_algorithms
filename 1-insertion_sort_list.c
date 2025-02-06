#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using the Insertion sort algorithm.
 *
 * @list: Pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *temp, *swap;

    if (!list || !(*list) || !(*list)->next)
        return;

    current = (*list)->next;
    while (current)
    {
        temp = current->prev;
        while (temp && current->n < temp->n)
        {
            // Swap nodes
            swap = current->next;
            if (current->next)
                current->next->prev = temp;
            if (temp->prev)
                temp->prev->next = current;

            current->prev = temp->prev;
            temp->next = current->next;
            current->next = temp;
            temp->prev = current;

            // If we're swapping at the head of the list
            if (!current->prev)
                *list = current;

            print_list(*list);
        }
        current = swap;
    }
}

