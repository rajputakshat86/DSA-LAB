#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push()
{
    int x;
    printf("Enter value: ");
    scanf("%d", &x);

    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = x;
    n->next = top;
    top = n;
}

void pop()
{
    if (top == NULL)
    {
        printf("Underflow\n");
        return;
    }
    struct Node *t = top;
    printf("Popped: %d\n", t->data);
    top = top->next;
    free(t);
}

void peek()
{
    if (top == NULL)
        printf("Empty\n");
    else
        printf("Top: %d\n", top->data);
}

void display()
{
    struct Node *t = top;
    if (t == NULL)
    {
        printf("Empty\n");
        return;
    }
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
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