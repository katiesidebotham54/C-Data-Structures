#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node
{
    int val;
    struct node *leftChild;
    struct node *rightChild;
};

struct node *createNode(int n)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->val = n;
    new_node->leftChild = new_node->rightChild = NULL;
    return new_node;
}

bool isEmpty(struct node *root)
{
    if (root == NULL)
    {
        return true;
    }
    return false;
}

struct node *insertNode(struct node *root, int n)
{
    //if the root is empty and the root value is not equal to it
    if (isEmpty(root))
    {
        //set root node equal to new node
        struct node *insertedNode = createNode(n);
        root = insertedNode;
        printf("inserted\n");
        return root;
    }
    else if (n < root->val)
    {
        root->leftChild = insertNode(root->leftChild, n);
    }
    else if (n > root->val)
    {
        root->rightChild = insertNode(root->rightChild, n);
    }
    else
    {
        printf("not inserted\n");
        return root;
    }
    return root;
}

void searchTree(struct node *root, int target)
{
    //if root is empty or target value is root then return root
    if (isEmpty(root))
    {
        printf("absent\n");
        return;
    }
    if (target == root->val)
    {
        printf("present\n");
        return;
    }
    else if (target < root->val)
    {
        //if target is less than root, then go to leftChild
        return searchTree(root->leftChild, target);
    }
    else
    {
        //otherwise go rightChild
        return searchTree(root->rightChild, target);
    }
}

void deallocate(struct node *root)
{
    if (isEmpty(root))
    {
        return;
    }
    deallocate(root->leftChild);
    deallocate(root->rightChild);
    root->rightChild = NULL;
    root->leftChild = NULL;
    free(root);
}

void printBST(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("(");
    printBST(root->leftChild);
    printf("%d", root->val);
    printBST(root->rightChild);
    printf(")");
    return;
}

int findMinValue(struct node *right)
{
    struct node *temp = right;
    while (temp->leftChild != NULL)
    {
        temp = temp->leftChild;
    }
    int min = temp->val;
    return min;
}

struct node *deleteNode(struct node *root, int n)
{
    if (isEmpty(root))
    {
        printf("absent\n");
        return root;
        //if val is less than ptr value, go leftChild
    }
    else if (n < root->val)
    {
        root->leftChild = deleteNode(root->leftChild, n);
        //if val is greater than ptr value, go rightChild
    }
    else if (n > root->val)
    {
        root->rightChild = deleteNode(root->rightChild, n);
    }
    //n is equal to root val
    else
    {
        if (root->leftChild == NULL)
        {
            struct node *curr = root;
            root = root->rightChild;
            free(curr);
            printf("deleted\n");
            return root;
            //if only contain leftChild
        }
        else if (root->rightChild == NULL)
        {
            struct node *curr = root;
            root = root->leftChild;
            free(curr);
            printf("deleted\n");
            return root;
            // if contain two children
        }
        else
        {
            int minRight = findMinValue(root->rightChild);
            root->val = minRight;
            root->rightChild = deleteNode(root->rightChild, minRight);
        }
    }
    return root;
}

int main(int argc, char *argv[])
{

    struct node *root = NULL;

    char action;
    int input;
    while (scanf(" %c%d", &action, &input) != EOF)
    {

        if (action == 'i')
        {
            root = insertNode(root, input);
        }
        else if (action == 'd')
        {
            root = deleteNode(root, input);
        }
        else if (action == 's')
        {
            searchTree(root, input);
        }
        else if (action == 'p')
        {
            printBST(root);
            printf("\n");
        }
    }
    deallocate(root);

    return 0;
}