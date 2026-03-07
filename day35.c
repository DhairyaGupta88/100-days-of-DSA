#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

// Enqueue operation
void enqueue(int value)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->next = NULL;

    if(front == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }

    printf("Inserted: %d\n", value);
}

// Dequeue operation
void dequeue()
{
    struct node *temp;

    if(front == NULL)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        temp = front;
        printf("Deleted: %d\n", front->data);
        front = front->next;
        free(temp);
    }
}

// Display operation
void display()
{
    struct node *temp;

    if(front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        temp = front;
        printf("Queue elements: ");

        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    display();

    return 0;
}