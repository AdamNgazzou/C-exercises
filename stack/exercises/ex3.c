// Online C compiler to run C program online
#include <stdio.h>


typedef struct{
    char name[50];
    int legs;
}animals;

typedef struct{
    int last ; 
    int size;
    animals stack[50];
}myStack;


int isEmpty(myStack p){
    return p.last==0;
}
int isFull(myStack p){
    return p.last ==p.size;
}
void push(myStack *p,animals animal){
    p->stack[p->last++]=animal;
}
animals pop(myStack *p){
    return p->stack[--p->last];
}

void display(myStack p){
    animals animal;
    while(!isEmpty(p)){
        animal = pop(&p);
        printf("name : %s \n",animal.name);
        printf("legs : %d \n",animal.legs);
    }
}
animals look(myStack p){
    return pop(&p);
}
void duplicate(myStack *p){
    push(p,look(*p));
}
void swap(myStack *p){
    animals a1 = pop(p);
    animals a2 = pop(p);
    push(p,a1);
    push(p,a2);
}
void DeleteBipates(myStack *p) {
    myStack x ;
    x.size = p->size;  
    x.last = 0;
    animals animal ;
    while(!isEmpty(*p)){
        animal = pop(p);
        if (animal.legs != 2) push(&x,animal); 
    }
    while(!isEmpty(x)){
        animal = pop(&x);
        push(p,animal); 
    }
    
    
}
int main() {
    myStack p;
    animals animal;
    int n;
    printf("give the size max of the stack 1");
    scanf("%d",&p.size);
    p.last=0;
    while(!isFull(p)){
        printf("name :");
        scanf("%s",animal.name);
        printf("number of legs : ");
        scanf("%d",&animal.legs);
        push(&p,animal);
    }
    display(p);
    DeleteBipates(&p);
    display(p);

    return 0;
}
