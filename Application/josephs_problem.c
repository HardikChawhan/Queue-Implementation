#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct
{
  int *data;
  int front;
  int rear;
  int capacity;
}Queue;

void initQueue(Queue *queue, int capacity){
  queue->data = (int *)malloc(capacity * sizeof(int));
  if (queue->data == NULL){
    printf("Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  queue->front = -1;
  queue->rear = -1;
  queue->capacity = capacity;
}

bool isFull(Queue *queue){
  if (queue->front == (queue->rear + 1)%queue->capacity)
  {
    return true;
  }
  else{
    return false;
  }
}

bool isEmpty(Queue *queue){
  if (queue->front == -1)
  {
    return true;
  }
  else{
    return false;
  }
}

void enqueue(Queue *queue,int element){
  if (isFull(queue))
  {
    printf("Queue overflow\n");
    return;
  }

  if (queue->front == -1)
  {
    queue->front = 0;
  }
  
  queue->rear = (queue->rear + 1)%queue->capacity;
  queue->data[queue->rear] = element;
  
}

int dequeue(Queue *queue){
  if (isEmpty(queue))
  {
    printf("Queue underflow\n");
    return -1;
  }

  int frontValue = queue->data[queue->front];
  if (queue->front == queue->rear)
  {
    queue->front = -1;
    queue->rear = -1;
  }
  else{
    queue->front = (queue->front + 1)%queue->capacity;
  }

  return frontValue;
}

int peek(Queue *queue){
  if (isEmpty(queue))
  {
    return -1;
  }
  else{
    return queue->data[queue->front];
  }

}

void printQueue(Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty\n");
    return;
  }

  int i = queue->front;
  while (true) {
    printf("%d ", queue->data[i]);
    if (i == queue->rear) break;
    i = (i + 1) % queue->capacity;
  }
  printf("\n");
}

void solveProblem(int n, int k){
  Queue queue;
  initQueue(&queue,n);

  for (int i = 1; i <= n; i++)
  {
    enqueue(&queue,i);
  }

  while (!isEmpty(&queue) && queue.front != queue.rear)
  {
    // rotate the queue k-1 times
    for (int i = 0; i < k-1; i++)
    {
      enqueue(&queue, dequeue(&queue));
    }

    printf("Eliminated: %d\n", dequeue(&queue));
  }
  
  printf("Winner: %d\n",dequeue(&queue));
  
}

int main(){

  solveProblem(10,7);
  return 0;
}