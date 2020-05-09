#include <stdio.h>
#include <stdlib.h>

typedef struct MinStack{
    int data;
    int min;
    struct MinStack* next;
} MinStack;

/** initialize your data structure here. */

void printStack(MinStack* obj) {
  MinStack* p = NULL;
  printf("\nMinStack: [ ");
  for (p=obj; p; p=p->next) {
      printf("%d->", p->data);
  }
  printf("]");
}

MinStack* minStackCreate() {
    MinStack* min_stk = (MinStack*)malloc(sizeof(MinStack));
    min_stk->next = NULL;
    min_stk->data = -1;
    min_stk->min = INT_MIN;
    return min_stk;
}

void minStackPush(MinStack **obj, int x) {
  MinStack* node = (MinStack*)malloc(sizeof(MinStack));
  printf(">");printStack(obj);
  node->data = x;
  node->next = *obj;
  *obj = node;
  printf(">>");printStack(obj);
}

void minStackPop(MinStack* obj) {
  
}

int minStackTop(MinStack* obj) {
  
}

int minStackGetMin(MinStack* obj) {
  
}

void minStackFree(MinStack* obj) {
    
}

int main() {
    MinStack* obj = minStackCreate();
    obj->data = 100;
    printStack(obj);
    minStackPush(&obj, 10);
    printf("+");printStack(obj);
    minStackPush(&obj, 4);
    minStackPush(&obj, 13);
    printStack(obj);
    // minStackPop(obj);
    // minStackPop(obj);
    // minStackPush(obj, 2);
    // minStackPush(obj, 29);
}
/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/