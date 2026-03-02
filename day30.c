//#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct Node {
    int data;
    struct Node* next;
};

// Function to create linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int i;

    for(i = 1; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Function to rotate list right by k
struct Node* rotateRight(struct Node* head, int k) {
    if(head == NULL || k == 0)
        return head;

    struct Node *temp = head;
    int length = 1;

    // Count length
    while(temp->next != NULL) {
        temp = temp->next;
        length++;
    }

    // Make circular
    temp->next = head;

    k = k % length;
    int steps = length - k;

    // Move to new last node
    temp = head;
    for(int i = 1; i < steps; i++) {
        temp = temp->next;
    }

    // New head
    head = temp->next;

    // Break circle
    temp->next = NULL;

    return head;
}

// Function to display list
void display(struct Node* head) {
    while(head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    int n, k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node* head = createList(n);

    printf("\nOriginal List:\n");
    display(head);

    printf("\nEnter value of k: ");
    scanf("%d", &k);

    head = rotateRight(head, k);

    printf("\nRotated List:\n");
    display(head);

    return 0;
}