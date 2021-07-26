#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef int status;

#define INIT_SIZE 10

typedef struct {
    int *top;
    int *bottom;
    int size;
}Stack;

status InitStack(Stack &stack){
    stack.bottom = new int[INIT_SIZE];
    if(!stack.bottom) exit(OVERFLOW);
    stack.top = stack.bottom;
    stack.size = INIT_SIZE;
    return OK;
}

bool Empty(Stack stack){
    return stack.top == stack.bottom;
}


status GetTop(Stack stack, int &elem){
    if(stack.top == stack.bottom) return ERROR;
    elem = *(stack.top - 1);
    return OK;
}

status Push(Stack &stack, int elem){
    if(stack.top - stack.bottom >= stack.size){
        int *temp = new int[stack.size*2];
        temp = stack.bottom;
        stack.bottom = temp;
        stack.top = stack.bottom + stack.size;
        stack.size = stack.size*2;
    }
    *stack.top++ = elem;
    return OK;
}

status Pop(Stack &stack, int &elem){
    if(stack.top == stack.bottom) return ERROR;
    elem = *--stack.top;
    return OK;
}
