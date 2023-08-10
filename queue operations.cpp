#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure for the queue
struct Queue {
    int arr[MAX_SIZE];
    int front, rear;
};

// Function to initialize the queue
void initialize(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// Function to enqueue an element
void enqueue(struct Queue* queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full: Cannot enqueue element %d\n", data);
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
    }

    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->arr[queue->rear] = data;
    printf("Enqueued %d into the queue.\n", data);
}

// Function to dequeue an element
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty: Cannot dequeue element.\n");
        return -1; // Return a sentinel value to indicate an error
    }

    int dequeued = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        // Last element is dequeued, reset the queue
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    return dequeued;
}

// Function to display the queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    int current = queue->front;
    printf("Queue: ");
    while (current != queue->rear) {
        printf("%d -> ", queue->arr[current]);
        current = (current + 1) % MAX_SIZE;
    }
    printf("%d\n", queue->arr[current]);
}

int main() {
    struct Queue queue;
    initialize(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    display(&queue);

    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));

    display(&queue);

    return 0;
}

