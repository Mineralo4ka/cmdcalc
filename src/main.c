#include <stdio.h>
#include <string.h>
#define NMAX 100

struct stack {
    char elem[NMAX];
    int top; //вершина
};

void push(struct stack *stk, float f)
{
    if(stk->top < NMAX) {
        stk->elem[stk->top] = f;
        stk->top++;
    } else {
        printf("Стек полон, количество элементов: %d !\n", stk->top);
    }
}

float pop(struct stack *stk)
{
    float elem;
    if((stk->top) > 0) {
        stk->top--;
        elem = stk->elem[stk->top];
        return elem;
    } else {
        printf("Стек пуст!\n");
        return 0;
    }
}

int main(int argc, char **argv) 
{
    if(argc <= 1) {
        printf("Некорректные значения\n");
        return 1;
    }

    //float num[128];
    //char ops[128];

    for (int i = 1; i < argc; ++i)
    {
        printf("%s ", argv[i]);
    }
    printf("\n");
    //for(int i = 1; i < argc; i++) {
    //    if (sscanf(argv[i], "%d", &a) =) 
    //}
 
    
    return 0;
}