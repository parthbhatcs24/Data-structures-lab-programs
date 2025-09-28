#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Stack operations
void push(char c)
{
    if (top < MAX - 1)
        stack[++top] = c;
    else
        printf("Stack Overflow\n");
}

char pop()
{
    if (top >= 0)
        return stack[top--];
    else
        return '\0'; // Empty stack
}

char peek()
{
    if (top >= 0)
        return stack[top];
    else
        return '\0';
}

// Function to return precedence of operators
int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

// Function to check if character is operator
int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert infix to postfix
void infixToPostfix(char infix[], char postfix[])
{
    int i, k = 0;
    char c;

    for (i = 0; i < strlen(infix); i++)
    {
        c = infix[i];

        if (isalnum(c))
        {
            // Operand, add to output
            postfix[k++] = c;
        }
        else if (c == '(')
        {
            push(c);
        }
        else if (c == ')')
        {
            while (top != -1 && peek() != '(')
            {
                postfix[k++] = pop();
            }
            pop(); // Remove '(' from stack
        }
        else if (isOperator(c))
        {
            while (top != -1 && precedence(peek()) >= precedence(c) && peek() != '(')
            {
                postfix[k++] = pop();
            }
            push(c);
        }
    }

    while (top != -1)
    {
        postfix[k++] = pop();
    }

    postfix[k] = '\0'; // Null-terminate string
}

int main()
{
    char infix[MAX], postfix[MAX];

    printf("Enter a valid infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
