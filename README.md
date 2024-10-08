﻿# Queue Implementation in C

This is a basic implementation of a queue data structure in the C programming language. The purpose of this project is to understand how a queue is written in the backend and how queue data structure is used.
## Features

- Initialize the queue.
- Enqueue elements into the queue.
- Dequeue elements from the queue.
- Peek at the front element of the queue.
- Print the contents of the queue.
- Check if the queue is empty or full.

## Prerequisites

- C compiler (GCC recommended)

## Usage

1. Clone the repository to your local machine:

    ```bash
    git clone https://github.com/HardikChawhan/Queue-Implementation.git
    ```

2. Navigate to the project directory:

    ```bash
    cd Queue-Implementation
    ```

3. Compile the code:

    ```bash
    gcc queue.c -o queue
    ```

4. Run the executable:

    ```bash
    ./queue
    ```

## Example

### Queue Initialization

```c
   Queue myQueue;
   initQueue(&myQueue, 5);
```

### Enqueuing Elements
```c
   enqueue(&myQueue, 10);
   enqueue(&myQueue, 20);
   enqueue(&myQueue, 30);
   enqueue(&myQueue, 40);
   enqueue(&myQueue, 50);
   enqueue(&myQueue, 60); // This will fail as the queue is full
```

### Dequeuing Elements
```c
   printf("Dequeue: %d\n", dequeue(&myQueue));
   printQueue(&myQueue);
```

### Peeking at the Front Element
```c
   printf("Peek: %d\n", peek(&myQueue));
   printQueue(&myQueue);
```

### Printing queue
```c
   printQueue(&myQueue);
```

### Checking Queue Empty/Full Status
```c
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
```
## Video Explanation - Click to watch

### Linear Queue 👇
[![Watch the video](https://img.youtube.com/vi/D6gu-_tmEpQ/hqdefault.jpg)](https://youtu.be/D6gu-_tmEpQ?si=-abSrbSU3xLhlwgk)

### Circular queue 👇
[![Watch the video](https://img.youtube.com/vi/ihEmEcO2Hx8/hqdefault.jpg)](https://youtu.be/ihEmEcO2Hx8?si=0dQeoJSA8uDNvz9S)

### Double Ended Queue (Dequeue)
[![Watch the video](https://img.youtube.com/vi/j3rvizohd0I/hqdefault.jpg)](https://youtu.be/j3rvizohd0I?si=yAdrVW9hR0zBcL51)


## 🔗 Profile Links
[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/hardikchawhan)
[![twitter](https://img.shields.io/badge/twitter-1DA1F2?style=for-the-badge&logo=twitter&logoColor=white)](https://twitter.com/ChawhanHardik)
[![Instagram](https://img.shields.io/badge/Instagram-E4405F?style=for-the-badge&logo=instagram&logoColor=white)](https://www.instagram.com/hardik_chawhan_10/)
