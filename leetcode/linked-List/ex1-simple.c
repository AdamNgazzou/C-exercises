// Online C compiler to run C program online
#include <stdio.h>
#include <stlib.h>
#include <string.h>

#define n 100 


typedef struct{
    int key [n];
    unsigned head ;
    int size ; 
    unsigned queue; 
}list

int isEmpty(list l){
    return l.head == l.queue ; 
}

int isFull(list l){
    return f.queue == f.size;
}

void enqueue(list *l,int val){
    l->key[l->queue++]=v;
}
void dequeue(list *l){
    return l->key[l->head++];
}

int main() {
    // Write C code here
    printf("Try programiz.pro");

    return 0;
}


