#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *create()
{
    int x;
    printf("Enter data (-1 for NULL): ");
    scanf("%d", &x);

    if (x == -1)
        return NULL;

    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = x;

    printf("Enter left child of %d\n", x);
    n->left = create();

    printf("Enter right child of %d\n", x);
    n->right = create();

    return n;
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    struct Node *root;

    printf("Create Binary Tree\n");
    root = create();

    printf("\nInorder: ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);

    return 0;
}