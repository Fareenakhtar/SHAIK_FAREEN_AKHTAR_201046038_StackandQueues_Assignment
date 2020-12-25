#include <stdlib.h>
#include <assert.h>
#include "stack.h"
#include "stack.h"

void test_empty_stack(){
    Stack   s1= stack_new(20);
    Stack   *stk = &s1;
    assert(stack_empty(stk));
}

void test_full_stack(){
    Stack s1 = stack_new(2);
    Stack *stk = &s1;
    StackResult res;
    stk = stack_push(stk,10,&res);
    assert(res.status == STACK_OK);
    stk = stack_push(stk,20,&res);
    assert(res.status==STACK_OK);
    stk = stack_push(stk,30,&res);
    assert(res.status==STACK_FULL);
    assert(stack_full(stk)==1);
}

void test_stack(){
    Stack s1 = stack_new(5);
    Stack *stk = &s1;
    StackResult res;
    stk = stack_pop(stk,&res);          
    assert(res.status == STACK_EMPTY);  

    stk = stack_push(stk,10,&res);
    stk = stack_push(stk,20,&res);
    stk = stack_peek(stk,&res);
    assert(res.status == STACK_OK && res.data ==20);

    stk = stack_pop(stk,&res);
    assert(res.status == STACK_OK && res.data ==20);
    stk = stack_peek(stk,&res);
    assert(res.status == STACK_OK && res.data ==10);
    stk = stack_pop(stk,&res);
    assert(stack_empty(stk) ==1);
}

void test_balance_syb(){
    Stack s1 = stack_new(6);
    Stack *stk = &s1;
    StackResult res;
    char symb="{[()]}";
    stk= balance_symbols(stk,symb);
    stk = stack_peek(stk,&res);

}


int main()
{
    //test_empty_stack();
    //test_full_stack();
    //test_stack();
    test_balance_syb();
    return 0;
}

