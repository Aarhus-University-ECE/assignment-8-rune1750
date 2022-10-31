#include "insertion_sort.h"
#include "linked_list.h"

#include <assert.h>

void sort(linked_list *llPtr)
{
    // placeholder nodes
    node_t *holder;
    node_t *holder_next;
    node_t *last = llPtr->head;
    node_t *current = last->next;
    node_t *place = llPtr->head;

    // Only runs the sorter if the list is not empty
    assert(llPtr->head == NULL);

    // runs untill last node == NULL
    while (last->next != NULL)
    {
        // If current node's data is smaller than the top node, current will be held by a placeholder
        if (current->data < last->data)
        {
            holder = current;
            holder_next = current->next;
            last->next = current->next;
            // Looks for a previous node which has data smaller than the current node
            while (place->next->data < holder->data)
            {
                place = place->next;
            }
            if (llPtr->head == place)
            {
                holder->next = llPtr->head;
                llPtr->head = holder;
            }
            else
            {
                holder->next = place->next;
                place->next = holder;
            }
        }
    }
    // sorting starts over, but with top element as the node with the smallest data found
    last = current;
    current = last->next;
}
