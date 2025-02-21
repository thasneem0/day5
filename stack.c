#include <stdio.h>
#define STACK_SIZE 1000
typedef float T;
typedef struct {
    T elements[STACK_SIZE];
    int _size;
    int _top;
} stack;

void stackinit(stack* stk);
void stackpush(stack* stk, T element);
int stackempty(stack* stk);
T stacktop(stack* stk);
void stackpop(stack* stk);

int main() {
    stack stk; 
    stackinit(&stk); 

    float salaries[] = {50000, 40800, 48000, 20000, 23000};

    for (int i = 0; i < 5; i++) {
        stackpush(&stk, salaries[i]);
    }

    printf("salaries from stack:\n");
    while (!stackempty(&stk)) {
        float sal = stacktop(&stk);
        printf("%f ", sal); 
        stackpop(&stk);
    }
    printf("\n"); 
    return 0;
}

void stackinit(stack* stk) {
    stk->_size = 0;
    stk->_top = -1; 
}

void stackpush(stack* stk, T element) {
    if (stk->_size < STACK_SIZE) { 
        stk->_top++;
        stk->elements[stk->_top] = element;
        stk->_size++;
    } else {
        printf("Stack Overflow!\n");
    }
}

int stackempty(stack* stk) {
    return (stk->_top == -1); 
}

T stacktop(stack* stk) {
    if (!stackempty(stk)) { 
        return stk->elements[stk->_top];
    } else {
        printf("Stack is empty, cannot get top element.\n");
        return 0; 
    }
}

void stackpop(stack* stk) {
    if (!stackempty(stk)) {
        stk->_top--;
        stk->_size--;
    } else {
        printf("Stack is empty, cannot pop.\n");
    }
}
