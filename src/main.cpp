extern "C"
{
// Add the header files required to run your main
#include <stdlib.h>
#include <stdio.h>
#include "list_queue.c"
#include "linked_list.h"
#include "linked_list.c"
#include <assert.h>

}

// File for sandboxing and trying out code
int main(int argc, char **argv)
{
// Test A
queue tester; 
init_queue(&tester);
assert(empty(&tester)==1);

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