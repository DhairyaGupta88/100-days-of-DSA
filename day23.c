//merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

// Structure for Node
struct Node {
    int data;
    struct Node* next;
};

// Function to create new node dynamically
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at end
struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Function to merge two sorted lists
struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    struct Node* mergedHead = NULL;
    struct Node* temp = NULL;

    while (head1 != NULL && head2 != NULL) {
        int value;

        if (head1->data <= head2->data) {
            value = head1->data;
            head1 = head1->next;
        } else {
            value = head2->data;
            head2 = head2->next;
        }

        if (mergedHead == NULL) {
            mergedHead = createNode(value);
            temp = mergedHead;
        } else {
            temp->next = createNode(value);
            temp = temp->next;
        }
    }

    // Add remaining elements
    while (head1 != NULL) {
        temp->next = createNode(head1->data);
        temp = temp->next;
        head1 = head1->next;
    }

    while (head2 != NULL) {
        temp->next = createNode(head2->data);
        temp = temp->next;
        head2 = head2->next;
    }

    return mergedHead;
}

// Function to display list
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    // First Sorted List
    head1 = insertEnd(head1, 1);
    head1 = insertEnd(head1, 3);
    head1 = insertEnd(head1, 5);

    // Second Sorted List
    head2 = insertEnd(head2, 2);
    head2 = insertEnd(head2, 4);
    head2 = insertEnd(head2, 6);

    printf("List 1: ");
    display(head1);

    printf("List 2: ");
    display(head2);

    struct Node* merged = mergeLists(head1, head2);

    printf("Merged List: ");
    display(merged);

    return 0;
}