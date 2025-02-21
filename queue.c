#include <stdio.h>
#define STACK_SIZE 1000
typedef float T;
typedef struct {
    T elements[STACK_SIZE];
    int _size;
    int _front;
    int _back;
} Queue;

void Queueinit(Queue* stk);
void Queuepush(Queue* stk, T element);
int Queueempty(Queue* stk);
T Queuefront(Queue* stk);
T Queueback(Queue*stk);
void stackpop(Queue* stk);

int main() {
    Queue stk; 
    Queueinit(&stk); 

    float salaries[] = {50000, 40800, 48000, 20000, 23000};

    for (int i = 0; i < 5; i++) {
        Queuepush(&stk, salaries[i]);
    }

    printf("salaries from stack:\n");
    while (!Queueempty(&stk)) {
        float sal = Queuetop(&stk);
        printf("%f ", sal); 
        stackpop(&stk);
    }
    printf("\n"); 
    return 0;
}

void Queueinit(Queue* stk) {
    stk->_size = 0;
    stk->_front = -1;
    stk->_back=-1;
}

void Queuepush(Queue* stk, T element) {
    stk->_back++;
   stk->elements[stk->_back]=element;
   stk->_size++;
   if(stk->_front==-1){
       stk->front=0;
   }
}

int Queueempty(Queue* stk) {
    return (stk->_front==-1);
}

T Queuefront(Queue* stk) {
    return stk->elemnts[stk->_front];
}
T Queueback(Queue* stk) {
    return stk->elemnts[stk->_back];
}

void Queuepop(Queue* stk) 
{
    if (!Queueempty(stk)) {
        printf("queue is empty\n");
        return
    }
        if(stk->front==stk->back){
             stk->_front=-1;
             stk->_back=-1;
             stk->_size=0;
        }else{
            stk->_front++;
        }
}
