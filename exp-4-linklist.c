#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue()
{
    int x;
    printf("Enter value: ");
    scanf("%d", &x);

    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = x;
    n->next = NULL;

    if (rear == NULL)
    {
        front = rear = n;
        return;
    }

    rear->next = n;
    rear = n;
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Underflow\n");
        return;
    }

    struct Node *t = front;
    printf("Deleted: %d\n", t->data);
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(t);
}

void display()
{
    struct Node *t = front;

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
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 1)
            enqueue();
        else if (ch == 2)
            dequeue();
        else if (ch == 3)
            display();
        else
            break;
    }
}