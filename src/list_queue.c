#include "list_queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void init_queue(queue *q)
{
  // Full reset of the queue
  q->front = NULL;
  q->rear = NULL;
  q->size = 0;
}

int empty(queue *q)
{
  // If the front of the queue is NULL, the rear of the que will be set to NULL aswell
  if (q->front == NULL)
  {
    q->rear = NULL;
    printf("\nThe queue has been left abandoned... T_T");
    return 1;
    // que size reset
    q->size = 0;
  }
  else
  {
    printf("\nThere is something in this queue! ^_^");
    return 0;
  }
}

void enqueue(queue *q, int x)
{
  struct qnode *element = malloc(sizeof(qnode));
  element->data = x;
  element->next = NULL;

  // if queue is empty, the inserted element will be both front and rear
  if (q->front == NULL && q->rear == NULL)
  {
    q->rear = element;
    q->front = element;
  }
  else
  // if queue isnt empty, element will be the rear.
  {
    q->rear->next = element;
    q->rear = element;
  }
  // size of the queue is adjusted.
  q->size++;
}

int dequeue(queue *q)
{
  struct qnode *holder;
  int x; 
  // If the first place in the queue is empty, the program will print this.
  if (q->front == NULL)
  {
    printf("I dont have anything, leave me alone!");
  }
  else
  {
    // Front of the queue becomes the second element. qnode "holder" extracts information from queue.
    holder = q->front;
    q->front = q->front->next;
    // size of the queue is adjusted.
    x = holder->data; 
    free(holder); 
    q->size--;
  }
  return x;
}
