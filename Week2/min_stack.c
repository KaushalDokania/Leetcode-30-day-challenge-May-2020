#include <stdio.h>
#include <stdlib.h>

typedef struct MinStk{
    int data;
    struct MinStk* next;
} MinStk;

typedef MinStk* MinStack;
/** initialize your data structure here. */
MinStk *min_stk = NULL;
int min_data = INT_MAX;;

void printStack(MinStk **obj) {
  MinStk *p = NULL;
  printf("MinStack: [ ");
  for (p=*obj; p; p=p->next) {
      printf("%d->", p->data);
  }
  printf("]\n");
}

MinStk** minStackCreate() {
    //min_stk = (MinStk*)malloc(sizeof(MinStk));
    // min_stk->data = 0;
    // printf("After Create, ");printStack(&min_stk);
    return &min_stk;
}

void minStackPush(MinStk **obj, int x) {
  MinStk* node = (MinStk*)malloc(sizeof(MinStk));
  printf("Before push, ");printStack(obj);
  node->data = x;
  node->next = *obj;
  *obj = node;
  if(x < min_data)
    min_data = x;
  printf("After push, ");printStack(obj);
}

void minStackPop(MinStk **obj) {
  MinStk *top = *obj;
  *obj = top->next;
  free(top);
}

int minStackTop(MinStk **obj) {
  int data = (*obj)->data;
  if (data)
}

int minStackGetMin(MinStk **obj) {
  
}

void minStackFree(MinStk **obj) {
    
}

int main() {
    //MinStack *stk = minStackCreate();MinStack **obj = &stk;
    //MinStk **obj = minStackCreate();
    MinStack *obj = minStackCreate();
    printf("Created stack, ");printStack(obj);printf("\n");

    minStackPush(obj, 101);
    printf("pushed, ");printStack(obj);printf("\n");

    minStackPush(obj, 4);
    printf("pushed, ");printStack(obj);printf("\n");

    minStackPush(obj, 13);
    printf("pushed, ");printStack(obj);printf("\n");

    minStackPop(obj);
    printf("popped, ");printStack(obj);printf("\n");

    printf("top: %d", minStackTop(obj));
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