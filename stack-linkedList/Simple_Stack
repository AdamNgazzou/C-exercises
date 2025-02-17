// Online C compiler to run C program online
#include <stdio.h>

typedef struct{
    int last ; 
    int size;
    int stack[50];
}myStack;

int isEmpty(myStack p){
    return p.last==0;
}
int isFull(myStack p){
    return p.last ==p.size;
}
void push(myStack *p,int v){
    p->stack[p->last++]=v;
}
int pop(myStack *p){
    return p->stack[--p->last];
}


int main() {
    myStack p1,p2;
    int n;
    printf("give the size max of the stack 1");
    scanf("%d",&p1.size);
    p1.last=0;
    while(!isFull(p1)){
        printf("give a value :");
        scanf("%d",&n);
        push(&p1,n);
    }
    while(!isEmpty(p1)){
        printf("%d\n",pop(&p1));
    }

    return 0;
}



