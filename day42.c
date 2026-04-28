//Given a queue of integers, reverse the queue using a stack.
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue implementation
int queue[MAX];
int front = -1, rear = -1;

// Stack implementation
int stack[MAX];
int top = -1;

// Queue functions
void enqueue(int x) {
    if (rear == MAX - 1) return;

    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

// Stack functions
void push(int x) {
    if (top == MAX - 1) return;
    stack[++top] = x;
}

int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

// Reverse queue using stack
void reverseQueue() {
    // Step 1: Queue → Stack
    while (front != -1 && front <= rear) {
        push(dequeue());
    }

    // Reset queue pointers
    front = 0;
    rear = -1;

    // Step 2: Stack → Queue
    while (top != -1) {
        enqueue(pop());
    }
}

// Display queue
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }

    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Main function
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    printf("Original Queue: ");
    display();

    reverseQueue();

    printf("Reversed Queue: ");
    display();

    return 0;
}