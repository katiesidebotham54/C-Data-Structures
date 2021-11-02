#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Stack
{
    int top;
    int size;
    char *arr;
};

//check if stack is empty
bool isEmpty(int n)
{
    if (n == -1)
    {
        return true;
    }
    return false;
}

//free allocated memory in stack
void freeStack(struct Stack *stack)
{
    if (isEmpty(stack->top))
    {
        return;
    }
    else
    {
        free(stack->arr);
        free(stack);
    }
}

//
struct Stack *createStack(int maxSize, char *strInput)
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    //initailize all values
    s->top = -1;
    s->size = maxSize;
    s->arr = (char *)malloc(sizeof(char) * maxSize);

    return s;
}

void push(struct Stack *s, char c)
{
    if (s->top == (s->size - 1))
    {
        printf("push failed\n");
        exit(EXIT_FAILURE);
    }
    else
    {

        s->top += 1;
        s->arr[s->top] = c;
        printf("inserted: %c \n", c);
    }
}

void pop(struct Stack *s)
{
    if (isEmpty(s->top))
    {
        printf("pop method: stack is empty");
        return;
    }
    else
    {
        s->top--;
        return;
    }
}

void printStack(struct Stack *s)
{

    if (isEmpty(s->top))
    {
        printf("Stack is empty!!\n");
    }
    else
    {
        printf("Stack is...");
        for (int i = s->top; i >= 0; --i)
        {
            printf("%c ", s->arr[i]);
        }
        printf("\n");
    }
}

char peek(struct Stack *s)
{
    return s->arr[s->top];
}

bool isMatching(char c1, char c2)
{
    printf("Check if they match\n");
    if ((c1 == ')' && c2 == '(') || (c1 == '}' && c2 == '{') || (c1 == ']' && c2 == '['))
    {
        printf("They match!!\n");
        return true;
    }
    return false;
}

void balance(struct Stack *stack, char *inputStr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("========================\n");

        printf("iteration: %d\n", i);
        printf("========================\n");
        printf("char: %c\n", inputStr[i]);
        if (inputStr[i] == '(' || inputStr[i] == '{' || inputStr[i] == '[')
        {
            push(stack, inputStr[i]);
        }
        if (inputStr[i] == ')' || inputStr[i] == '}' || inputStr[i] == ']')
        {
            printf("top: %c\n", peek(stack));
            if ((!isMatching(inputStr[i], peek(stack))) || (isEmpty(stack->top)))
            {
                printf("%d: %c\n", i, inputStr[i]);
                exit(EXIT_FAILURE);
            }
            else
            {
                printf("popping!\n");
                pop(stack);
                printf("top after pop: %c\n", peek(stack));
            }
        }

        printStack(stack);
    }
    if (!isEmpty(stack->top))
    {
        printf("open: ");
        for (int i = stack->top; i >= 0; --i)
        {
            if (stack->arr[i] == '(')
            {
                printf(")");
            }
            else if (stack->arr[i] == '{')
            {
                printf("}");
            }
            else
            {
                printf("]");
            }
        }
    }
    else
    {
        exit(EXIT_SUCCESS);
    }
}

int main(int argc, char *argv[])
{
    int size = strlen(argv[1]);
    char str[size];
    struct Stack *stack = createStack(size, str);
    balance(stack, argv[1], size);
    freeStack(stack);
    return 0;
}
