// Add the header files required to run your main
#include <stdlib.h>
#include <stdio.h>
#include "list_queue.c"
#include "linked_list.h"
#include "linked_list.c"
#include "insertion_sort.c"
#include <assert.h>

// File for sandboxing and trying out code
int main(int argc, char **argv)
{
   int testerList3[10] = {6,6,5,4,2,3,3,3,2,1};
    int sortedList3[10] = {1,2,2,3,3,3,4,5,6,6};

    int testlist[10] = {6,6,5,4,2,3,3,3,2,1};
    linked_list *test = createLinkedList();
    for (int i = 0; i < 10; i++)
    {
        insertFront(createNode(testlist[10 - i - 1]), test);
    }

    printLL(test);
    sort(test);
    printLL(test); 
    

    // Test A
    queue tester;
    init_queue(&tester);
    assert(empty(&tester) == 1);

    // Test B
    int x = 10;
    int y;
    enqueue(&tester, x);
    y = dequeue(&tester);
    assert(y == x);

    // Test C
    int x0, x1, y0, y1;
    enqueue(&tester, x0);
    enqueue(&tester, x1);
    y0 = dequeue(&tester);
    y1 = dequeue(&tester);
    assert(x0 == y0 && x1 == y1);
}