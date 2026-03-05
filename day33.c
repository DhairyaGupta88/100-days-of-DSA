//: Convert an infix expression to postfix notation using stack.
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

int precedence(char x)
{
    if(x == '^')
        return 3;
    else if(x == '*' || x == '/')
        return 2;
    else if(x == '+' || x == '-')
        return 1;
    else
        return 0;
}

int main()
{
    char infix[MAX], postfix[MAX];
    int i, j = 0;

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    for(i = 0; i < strlen(infix); i++)
    {
        char symbol = infix[i];

        if(isalnum(symbol))
        {
            postfix[j++] = symbol;
        }
        else if(symbol == '(')
        {
            push(symbol);
        }
        else if(symbol == ')')
        {
            while(stack[top] != '(')
                postfix[j++] = pop();
            pop();
        }
        else
        {
            while(top != -1 && precedence(stack[top]) >= precedence(symbol))
                postfix[j++] = pop();
            push(symbol);
        }
    }

    while(top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("Postfix Expression: %s", postfix);

    return 0;
}