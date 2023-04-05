#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

typedef struct {
    int data;
} element;

element stack[MAX_SIZE];
int top = -1;

int is_empty()
{
    return (top == -1);
}

int is_full()
{
    return (top == (MAX_SIZE - 1));
}

void push(element item)
{
    if (is_full())
    {
        fprintf(stderr, "Stack Full!!\n");
        return;
    }
    else stack[++top] = item;
}

element pop(int i)
{
    if (is_empty())
    {
        fprintf(stderr, "Stack Emtpy!!\n");
        printf("[%d] pop: %d\n", i, top);
        element empty_elem = { -1 };
        return empty_elem;
    }
    else {
        printf("[%d] pop : %d\n", i, stack[top].data);
        return stack[top--];
    }
}

int main(void)
{
    srand(time(NULL));
    int rand_num;
    printf("------using struct------\n");

    for (int i = 1; i <= 30; i++)
    {
        rand_num = rand() % 100 + 1;
        if (rand_num % 2 == 0)
        {
            element new_elem = { rand_num };
            push(new_elem);
            printf("[%d] push : %d\n", i, rand_num);

        }
        else {
            pop(i);
        }
    }
    system("pause");
    return 0;
}