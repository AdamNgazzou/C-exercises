// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct stack{
  int key ;
  struct stack *next;
};

struct stack *create_stack(){
    return (NULL);
} 

unsigned empty_stack(struct stack *p){
    return(p==NULL);
}
int last(struct stack *p){
    assert(!empty_stack(p));
    return (p->key);
}
int push(int value ,struct stack **p){
    struct stack *q ;
    q = (struct stack *)malloc(sizeof(struct stack));    
    q->key=value;
    q->next = *p;
    *p=q;
} 
void pop(struct stack **p){
    struct stack *q ;
    assert(!empty_stack(*p));
    q=*p;
    *p=(*p)->next ;
    free(q);
}

void main() {
    struct stack *p;
    int n,y;
    struct stack *x;
    p=create_stack();
    x=create_stack();
    int i;
    for(i=0;i<5;i++){
        push(i,&p);
    }
    for(i=0;i<4;i++){
        push(p->key,&x);
        pop(&p);
    }
    y=p->key;
    do{
        printf("give a value");
        scanf("%d",&n);
    }while(n>y);
    push(n,&x);
    for(i =0;i<5;i++){
        printf("%d\n ",last(x));
        pop(&x);
    }
}








