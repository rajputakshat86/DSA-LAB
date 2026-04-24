#include <stdio.h>
#define MAX 5

int stack[MAX], top = -1;

void push()
{
    int x;
    if (top == MAX - 1)
    {
        printf("Overflow\n");
        return;
    }
    printf("Enter value: ");
    scanf("%d", &x);
    stack[++top] = x;
}

void pop()
{
    if (top == -1)
    {
        printf("Underflow\n");
        return;
    }
    printf("Popped: %d\n", stack[top--]);
}

void peek()
{
    if (top == -1)
        printf("Empty\n");
    else
        printf("Top: %d\n", stack[top]);
}

void display()
{
    if (top == -1)
    {
        printf("Empty\n");
        return;
    }
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main()
{
    int ch;
    while (1)
    {
        printf("\n1.Push 2.Pop 3.Peek 4.Display 5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 1)
            push();
        else if (ch == 2)
            pop();
        else if (ch == 3)
            peek();
        else if (ch == 4)
            display();
        else
            break;
    }
}