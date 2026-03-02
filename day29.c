// Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

// Define structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        
        printf("Enter data for node %d: ", i);
        scanf("%d", &newNode->data);
        
        if(head == NULL) {
            head = newNode;
            newNode->next = head;   // Point to itself
            temp = head;
        }
        else {
            temp->next = newNode;
            newNode->next = head;   // Make it circular
            temp = newNode;
        }
    }

    // Traversal
    printf("\nCircular Linked List elements are:\n");

    if(head != NULL) {
        temp = head;
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while(temp != head);
    }

    printf("(Back to Head)\n");

    return 0;
}