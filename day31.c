// Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

// Structure for polynomial node
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;

    return newNode;
}

// Insert node in descending order of exponent
struct Node* insert(struct Node* head, int c, int e) {
    struct Node* newNode = createNode(c, e);

    // If list is empty OR exponent is greater than head exponent
    if (head == NULL || e > head->exp) {
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;

    // Traverse to find correct position
    while (temp->next != NULL && temp->next->exp > e) {
        temp = temp->next;
    }

    // If exponent already exists, add coefficients
    if (temp->next != NULL && temp->next->exp == e) {
        temp->next->coeff += c;
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }

    return head;
}

// Display polynomial
void display(struct Node* head) {
    if (head == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }

    struct Node* temp = head;

    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

// Free memory
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* poly = NULL;
    int n, coeff, exp;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);
        poly = insert(poly, coeff, exp);
    }

    printf("\nPolynomial is: ");
    display(poly);

    freeList(poly);

    return 0;
}