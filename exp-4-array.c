#include <stdio.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;

void enqueue()
{
    int x;

    if (rear == MAX - 1)
    {
        printf("Overflow\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &x);

    if (front == -1)
        front = 0;

    queue[++rear] = x;
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Underflow\n");
        return;
    }

    printf("Deleted: %d\n", queue[front++]);

    if (front > rear)
        front = rear = -1;
}

void display()
{
    if (front == -1 || front > rear)
    {
        printf("Empty\n");
        return;
    }

    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);

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