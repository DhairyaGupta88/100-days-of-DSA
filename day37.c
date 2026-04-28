//Priority Queue using an array. An element with smaller value has higher priority.
#include <stdio.h>
#define MAX 100

int pq[MAX];
int size = 0;

// Insert element (maintain sorted order)
void enqueue(int value) {
    if (size == MAX) {
        printf("Priority Queue Overflow\n");
        return;
    }

    int i = size - 1;

    // Shift elements to maintain sorted order
    while (i >= 0 && pq[i] > value) {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1] = value;
    size++;

    printf("Inserted: %d\n", value);
}

// Remove highest priority element (smallest)
int dequeue() {
    if (size == 0) {
        printf("Priority Queue Underflow\n");
        return -1;
    }

    int value = pq[0];

    // Shift elements left
    for (int i = 1; i < size; i++) {
        pq[i - 1] = pq[i];
    }

    size--;

    return value;
}

// Peek (smallest element)
int peek() {
    if (size == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    return pq[0];
}

// Display queue
void display() {
    if (size == 0) {
        printf("Queue is empty\n");
        return;
    }

    printf("Priority Queue: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", pq[i]);
    }
    printf("\n");
}

// Main function
int main() {
    enqueue(30);
    enqueue(10);
    enqueue(20);
    enqueue(5);

    display();

    printf("Deleted: %d\n", dequeue());
    display();

    printf("Peek: %d\n", peek());

    return 0;
}