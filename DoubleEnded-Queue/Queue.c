#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
  int *data;
  int front;
  int rear;
  int capacity;
} Queue;

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

bool isEmpty(Queue *queue){
  return (queue->front == -1)?true:false;
}

void enqueueFront(Queue *queue, int element){
  if (queue->front == 0 && queue->rear == queue->capacity-1 || queue->front == queue->rear+1)
  {
    printf("Queue overflow\n");
    return;
  }
  
  if (isEmpty(queue))
  {
    queue->front = queue->rear = 0;
  }
  else if(queue->front==0){
    queue->front = queue->capacity-1;
  }
  else{
    queue->front--;
  }
  queue->data[queue->front] = element;
}

void enqueueRear(Queue *queue, int element){
  if (queue->front == (queue->rear+1)%queue->capacity)
  {
    printf("Queue overflow\n");
    return;
  }

  if (isEmpty(queue))
  {
    queue->front = 0;
  }
  queue->rear = (queue->rear+1)%queue->capacity;
  queue->data[queue->rear] = element;
}

int dequeueFront(Queue *queue){
  if (isEmpty(queue))
  {
    printf("Queue underflow\n");
    return -1;
  }
  
  int front = queue->data[queue->front];

  if (queue->front == queue->rear)
  {
    queue->front = -1;
    queue->rear = -1;
  }
  else{
  queue->front = (queue->front+1)%queue->capacity;
  }
  return front;
}

int dequeueRear(Queue *queue){
  if (isEmpty(queue))
  {
    printf("Queue underflow\n");
    return -1;
  }
  
  int rear = queue->data[queue->rear];
  
  if (queue->front == queue->rear)
  {
    queue->front = -1;
    queue->rear = -1;
  }
  else if(queue->rear == 0){
    queue->rear = queue->capacity-1;
  }
  else{
    queue->rear--;
  }
  return rear;
  
}

void printQueue(Queue *queue){
  if (isEmpty(queue))
  {
    printf("Empty queue\n");
    return;
  }
  int i = queue->front;
  while (true)
  {
    printf("%d ",queue->data[i]);
    if (i == queue->rear) break;

    i = (i+1)%queue->capacity;
  }
  printf("\n");
}

int main(){
  Queue myQueue;
  initQueue(&myQueue,5);

  enqueueFront(&myQueue,2);
  enqueueFront(&myQueue,5);
  enqueueFront(&myQueue,4);
  enqueueRear(&myQueue,1);
  enqueueRear(&myQueue,8);
  printQueue(&myQueue);

  dequeueFront(&myQueue);
  printQueue(&myQueue);

  dequeueRear(&myQueue);
  printQueue(&myQueue);
  return 0;
}