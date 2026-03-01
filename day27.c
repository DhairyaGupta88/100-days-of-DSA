//Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

// Structure of Linked List
struct Node {
    int data;
    struct Node* next;
};

// Function to create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to find intersection point
struct Node* getIntersectionNode(struct Node* headA, struct Node* headB) {
    
    if (headA == NULL || headB == NULL)
        return NULL;

    struct Node* ptr1 = headA;
    struct Node* ptr2 = headB;

    while (ptr1 != ptr2) {
        ptr1 = (ptr1 == NULL) ? headB : ptr1->next;
        ptr2 = (ptr2 == NULL) ? headA : ptr2->next;
    }

    return ptr1;  // Either intersection node or NULL
}

int main() {

    // Creating common part
    struct Node* common = createNode(40);
    common->next = createNode(50);

    // List A
    struct Node* headA = createNode(10);
    headA->next = createNode(20);
    headA->next->next = createNode(30);
    headA->next->next->next = common;

    // List B
    struct Node* headB = createNode(15);
    headB->next = createNode(25);
    headB->next->next = common;

    struct Node* intersection = getIntersectionNode(headA, headB);

    if (intersection != NULL)
        printf("Intersection Point: %d\n", intersection->data);
    else
        printf("No Intersection\n");

    return 0;
}