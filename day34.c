//Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));

    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop()
{
    struct node *temp;
    int x;

    if(top == NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    temp = top;
    x = temp->data;
    top = top->next;
    free(temp);

    return x;
}

int evaluate(char postfix[])
{
    int i = 0;
    int a, b, result;

    while(postfix[i] != '\0')
    {
        if(isdigit(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else
        {
            b = pop();
            a = pop();

            switch(postfix[i])
            {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    result = a / b;
                    break;
            }

            push(result);
        }

        i++;
    }

    return pop();
}

int main()
{
    char postfix[50];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    int result = evaluate(postfix);

    printf("Result = %d", result);

    return 0;
}