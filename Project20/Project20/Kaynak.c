#include <stdio.h> 
#include <stdlib.h> 

struct Queue {
    int front, rear, size;
    int x; //x = capacity
    int* array;
};
struct Queue* cQueue(int x)
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->x = x;
    queue->front = queue->size = 0;

    queue->rear = x - 1;
    queue->array = (int*)malloc(queue->x * sizeof(int));
    return queue;
}
int full(struct Queue* queue)
{
    return (queue->size == queue->x);
}
int empty(struct Queue* queue)
{
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item)
{
    if (full(queue))
        return 0;
    queue->rear = (queue->rear + 1) % queue->x;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
   
}


int dequeue(struct Queue* queue)
{
    if (empty(queue))
        return 0 ;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->x;
    queue->size = queue->size - 1;
    return item;
}


int front(struct Queue* queue)
{
    if (empty(queue))
        return 0;
    return queue->array[queue->front];
}
int rear(struct Queue* queue)
{
    if (empty(queue))
        return 0;
    return queue->array[queue->rear];
}

int main()
{
    struct Queue* queue1 = cQueue(15);
    struct Queue* queue2 = cQueue(15);
    struct Queue* queue3 = cQueue(15);
    for (int i = 0; i < 15; i++) {
        enqueue(queue1, rand() % 101);
    }

    for (int i = 0; i < 15; i++) {
        if (queue1->array[i] < 50) {
            enqueue(queue2, dequeue(queue1));
        }
        else {
            enqueue(queue3, dequeue(queue1));
        }
    }
    printf("Queue 1 :");
    for (int i = 0; i < queue1->size; i++) {
        printf("\n%d ", queue1->array[i]);
    }
    printf("\nQueue 2 :");
    for (int i = 0; i < queue2->size; i++) {
        printf(" %d   ", queue2->array[i]);
    }
    printf("\nQueue 3 :");
    for (int i = 0; i < queue3->size; i++) {
        printf(" %d   ", queue3->array[i]);
    }
    return 0;
}