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
  if (queue->front == -1){
    return true;
  }
  else{
    return false;
  }
}

bool isFull(Queue *queue){
  if (queue->rear == queue->capacity -1){
    return true;
  }
  else {
    return false;
  }
}

void enqueue(Queue *queue, int element){
  if (isFull(queue)){
    printf("Queue overflow\n");
    return;
  }
  if (queue->front == -1){
    queue->front = 0;
  }
  queue->data[++queue->rear] = element;
}

int dequeue(Queue *queue){
  if (isEmpty(queue)){
    printf("queue underflow\n");
    return -1;
  }
  int frontElemetn = queue->data[queue->front++];

  if (queue->front > queue->rear)
  {
    queue->front = -1;
    queue->rear = -1;
  }
  
  return frontElemetn;
}

void printQueue(Queue *queue){
  if (isEmpty(queue)){
    printf("queue is empty\n");
    return;
  }
  else{
    for (int i = queue->front; i <= queue->rear; i++){
      printf("%d ", queue->data[i]);
    }
    printf("\n");
  }
}

int peek(Queue *queue){
  if (isEmpty(queue)){
    return -1;
  }
  else{
    return queue->data[queue->front];
  }
}

int main(){
  Queue myQueue;
  initQueue(&myQueue,5);

  enqueue(&myQueue, 10);
  enqueue(&myQueue, 20);
  enqueue(&myQueue, 30);
  enqueue(&myQueue, 40);
  enqueue(&myQueue, 50);
  enqueue(&myQueue, 60); // This will fail as the queue is full

  printQueue(&myQueue);

  printf("Dequeue: %d\n", dequeue(&myQueue));
  printQueue(&myQueue);

  printf("Peek: %d\n", peek(&myQueue));
  printQueue(&myQueue);

  // Checking if queue is empty
  if (isEmpty(&myQueue)) {
    printf("Queue is empty\n");
  } else {
    printf("Queue is not empty\n");
  }

  // Checking if queue is full
  if (isFull(&myQueue)) {
    printf("Queue is full\n");
  } else {
    printf("Queue is not full\n");
  }

  return 0;
}
