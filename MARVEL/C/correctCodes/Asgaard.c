#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the queue
#define MAX_SIZE 100

// Define a queue structure
struct Queue {
    char data[MAX_SIZE];
    int front, rear;
};

// Function to initialize the queue
void initializeQueue(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->rear == MAX_SIZE - 1);
}

// Function to enqueue an element
void enqueue(struct Queue* queue, char value) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        exit(EXIT_FAILURE);
    }

    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear++;
    }

    queue->data[queue->rear] = value;
}

// Function to dequeue an element
char dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        exit(EXIT_FAILURE);
    }

    char value = queue->data[queue->front];

    if (queue->front == queue->rear) {
        // Last element in the queue
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }

    return value;
}

// Function to print the queue elements
void printQueue(struct Queue* queue) {
    int i;
    for (i = queue->front; i <= queue->rear; i++) {
        printf("%c ", queue->data[i]);
    }
    printf("\n");
}

int main() {
    // Define the string
    char myString[] = {'D', 'V', 'J', 'D', 'D', 'U', 'G'};
    int length = sizeof(myString) / sizeof(myString[0]);

    // Initialize the queue
    struct Queue myQueue;
    initializeQueue(&myQueue);

    // Enqueue each character into the queue
    for (int i = 0; i < length; i++) {
        enqueue(&myQueue, myString[i]);
    }

    // Print the queue elements
    printQueue(&myQueue);

    return 0;
}
