// Create and Traverse Singly Linked List
#include <stdio.h>
#include <stdlib.h>

// Step 1: Define Node Structure
struct Node {
    int data;
    struct Node* next;
};

int main() {

    struct Node *head = NULL, *newNode, *temp;
    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Creating Linked List
    for(i = 0; i < n; i++) {

        // Allocate memory
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data for node %d: ", i+1);
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
        }
        else {
            temp = head;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Traversing Linked List
    printf("\nLinked List Elements are: ");
    temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");

    return 0;
}