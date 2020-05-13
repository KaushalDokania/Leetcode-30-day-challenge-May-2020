#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int data;
    struct MinStack* next;
} MinStack;

MinStack *stk=NULL, *min_stk=NULL;

/** initialize your data structure here. */

void printStack(MinStack* obj) {
  MinStack* p = NULL;
  printf("MinStack: [ ");
  for (p=obj; p; p=p->next) {
      printf("%d->", p->data);
  }
  printf("]\n");
}

MinStack* minStackCreate() {
    stk = NULL;
    min_stk = (MinStack*)malloc(sizeof(MinStack));                      // to store the list of minimum numbers in order
    min_stk->data = INT_MAX;
    return NULL;
}

void minStackPush(MinStack *obj, int x) {
  MinStack* node = (MinStack*)malloc(sizeof(MinStack));
  printf("Before push, ");printStack(obj);
  node->data = x;
  node->next = stk;
  stk = node;
  printf("After push, ");printStack(obj);
  if (x < min_stk->data) {                  // push x to min_stk
      MinStack *min_node = (MinStack*)malloc(sizeof(MinStack));
      min_node->data = x;
      min_node->next = min_stk;
      min_stk = min_node;
  }
}

void minStackPop(MinStack *obj) {
  MinStack* top = stk;
  stk = stk->next;
  if (top->data <= min_stk->data)                   // pop the top from min_stk as well
  {
      MinStack *min_stk_top = min_stk;
      min_stk = min_stk->next;
      free(min_stk_top);
  }
  free(top);
}

int minStackTop(MinStack *obj) {
  return stk->data;
}

int minStackGetMin(MinStack *obj) {
  return min_stk->data;
}

void minStackFree(MinStack *obj) {
    
}

int main() {
    //MinStack *stk = minStackCreate();MinStack **obj = &stk;
    MinStack *obj = minStackCreate();
    //MinStack **obj = minStackCreate();
    //(*obj)->data = 100;

    //char command[];
    //do while

    printf("Created stack, ");printStack(obj);printf("\n");

    minStackPush(obj, 10);
    printf("pushed, ");printStack(obj);printf("\n");

    minStackPush(obj, 4);
    printf("pushed, ");printStack(obj);printf("\n");

    minStackPush(obj, 13);
    printf("pushed, ");printStack(obj);printf("\n");
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