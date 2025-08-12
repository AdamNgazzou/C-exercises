// Online C compiler to run C program online
#include <stdio.h>
#include <stlib.h>
#include <string.h>
#include <assert.h>

#define n 100 


struct element {
    int key;
    struct element *next;
};
typedef queue{
    struct elemnent *head ;
    struct element *queue ;
};

void create_queue(queue *l){
    l->head = NULL;
    l->queue = NULL ;
}

unsigned queue_empty(queue l){
    return ((l.head==NULL)&&(l.queue==NULL));
}

int first(queue l){
    assert(!queue_empty(l));
    return ((l.head)->key);
}

void enqueue(int val, queue *l){
    struct element *e;
    e = (struct element *)malloc(sizeof(struct element));
    e->key = val ;
    e->next = NULL ;
    if(!queue_empty(*l)){
        l->queue->next=e
        l->queue = e;
    }
    else {
        l->head=e;
        l->queue=e;
    }
}

void dequeue(queue *l){
    struct element *q ;
    assert(!queue_empty(*l));
    q = l->head;
    l->head = q->next;
    free(q);
    if(l->head == NULL){
        l->queue = NULL ;
    }
}

int main() {
    // Write C code here
    printf("Try programiz.pro");

    return 0;
}


