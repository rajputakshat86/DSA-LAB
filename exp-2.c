#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert()
{
    int x;
    printf("Enter value: ");
    scanf("%d", &x);

    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = x;
    n->next = head;
    head = n;
}

void display()
{
    struct Node *t = head;
    while (t != NULL)
    {
        printf("%d -> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

int main()
{
    int ch;
    while (1)
    {
        printf("\n1.Insert 2.Display 3.Exit\n");
        scanf("%d", &ch);

        if (ch == 1)
            insert();
        else if (ch == 2)
            display();
        else
            break;
    }
    return 0;
}