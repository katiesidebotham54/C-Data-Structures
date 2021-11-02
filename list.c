#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int length = 0;
//creating data type linked list
struct node
{
    int val;
    struct node *next;
};

//method to free node when memory not used
void freeNode(struct node *x)
{
    struct node *curr;
    while (x != NULL)
    {
        curr = x;
        x = x->next;
        free(curr);
    }
}

//creates new node for insert
struct node *createNode(int n)
{
    struct node *new_node = malloc(sizeof(struct node));
    new_node->val = n;
    new_node->next = NULL;
    return new_node;
}

//methond to insert into linked list with temp pointer head and value to insert
struct node *sortedInsert(struct node *head, int n, struct node *new_node)
{

    //if head is null or the value is less than head value, insert
    if (head == NULL || head->val > n)
    {
        new_node->next = head;
        head = new_node;
        length++;
        return head;
    }
    if(head != NULL && head->val == n){
        freeNode(new_node);
        return head;
    }
    struct node *curr = head;
    //while next node is not null and the next value is less than n
    while (curr->next != NULL && curr->next->val < n)
    {
        //keep traversing
        curr = curr->next;
    }
    //if value already exists
    if (curr->next != NULL && curr->next->val == n)
    {
        return head;
        //insert node here
    }
    else if (curr->next != NULL && curr->next->val > n)
    {
        new_node->next = curr->next;
        curr->next = new_node;
        length++;
        //insert node at the end of the list
    }
    else
    {
        curr->next = new_node;

        length++;
    }
    return head;
}

//method to delete value from linked list
struct node *deleteNode(struct node *head, int n)
{
    if (head == NULL)
    {
        return head;
    }

    struct node *ptr = head;

    //if the target is the first element in list
    if (head != NULL && head->val == n)
    {
        head = ptr->next;
        free(ptr);
        length--;
        return head;
    }

    while (ptr->next != NULL)
    {
        //found the element to be deleted
        if (ptr->next->val == n)
        {
            struct node *temp = ptr->next;
            ptr->next = temp->next;
            length--;
            free(temp);
            return head;
        }
        else
        {
            ptr = ptr->next;
        }
    }

    return head;
}

void printList(struct node *head, int length)
{
    struct node *prtInput = head;

    printf("%d : ", length);
    while (prtInput != NULL)
    {
        if (prtInput->next == NULL)
        {
            printf("%d", prtInput->val);
        }
        else
        {
            printf("%d ", prtInput->val);
        }
        prtInput = prtInput->next;
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    struct node *head = NULL;
    char action;
    int input;

    while (scanf(" %c%d", &action, &input) != EOF)
    {
        if (action == 'i')
        {
            struct node *new_node = createNode(input);
            head = sortedInsert(head, input, new_node);
            printList(head, length);
        }
        else if (action == 'd')
        {
            head = deleteNode(head, input);
            printList(head, length);
        }
    }

    freeNode(head);
    free(head);

    return 0;
}