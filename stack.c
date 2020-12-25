#include <assert.h>
#include "stack.h"
#include <stdint.h>

Stack       stack_new(uint32_t size){
    size = (size > 0 && size < MAX_DEPTH)?  size: MAX_DEPTH; //if the size of the array is 0 or more thn max_depth, the size is set as max-depth by default
    Stack s1 = {size, -1, {0} }; //members of the stack is size, top and data. we initialize top of stack as -1. and data as 0. since there is no element in the stack.
    return s1;
}

uint8_t     stack_full(const Stack *stk){
    assert(stk !=NULL);
    return ((stk->top +1)== stk->size);
}

uint8_t     stack_empty(const Stack *stk){
    assert (stk!=NULL);
    return (stk->top == -1);
}

Stack*      stack_push(Stack *stk, float ele, StackResult *res){
    assert (stk!=NULL);
    if ((stk->top+1)< (stk->size))
    {
        stk->data[++stk->top] = ele; //only if the stack isn't full we can add the element
        res->status = STACK_OK;
        res->data = ele;
    }else
    {
        res->status=STACK_FULL;
    }
    return stk;
}

Stack* stack_pop(Stack *stk,StackResult *res){
    assert (stk !=NULL);
    if (stk->top !=-1){
        res->data = stk->data[stk->top];
        --stk->top;
        res->status=STACK_OK;
    }else{
        res ->status= STACK_EMPTY;
    }
    return stk;
}

Stack* stack_peek(Stack *stk, StackResult *res){
    assert(stk !=NULL);
    if (stk->top !=-1){
        res->data = stk->data[stk->top];
        res->status=STACK_OK;
    }else{
        res ->status= STACK_EMPTY;
    }
    return stk;
}

Stack*  balance_symbols(Stack *stk, char smb[]){
    int len,*res;
    len=strlen(smb);
    for(int i = 0; i < len; i++){
        if((smb[i] == '{') || (smb[i] == '[') || (smb[i] == '('))
            stack_push(stk,smb[i],*res);
        else if((smb[i] == '}') || (smb[i] == ']') || (smb[i] == ')'))
            stack_pop(stk,*res);
        else {
            return stk;
        }
    }return stk;
}
