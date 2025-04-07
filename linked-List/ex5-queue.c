// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct {
  char name[50];
  int area;
  int inhabitans;
}city;

struct element{
    city key ; 
    struct element *next;
};
typedef struct {
    struct element *head;
    struct element *tail;
}queue;

void create_queue(queue *q){
    q->head = NULL;
    q->tail = NULL;
}
int isEmpty(queue q){
    return (q.head == NULL && q.tail == NULL);
}
void enqueue(queue *q, city info){
    struct element *temp;
    temp = (struct element*)malloc(sizeof(struct element));
    temp->key = info ;
    temp->next = NULL;
    if(!isEmpty(*q)){
        q->tail->next = temp;
        q->tail = temp ;
    }else{
        q->head = temp;
        q->tail = temp;
    }
}
city look(queue q){
    assert(!isEmpty(q));
    return (q.head)->key;
}
void dequeue(queue *q){
    struct element *temp;
    assert(!isEmpty(*q));
    temp = q->head;
    q->head = temp->next;
    free(temp);
    if(q->head == NULL){
        q->tail = NULL;
    }
    
}
void deleteThirdCity(queue *q){
    if (q->head == NULL || q->head->next == NULL || q->head->next->next == NULL) return ;
    struct element *second = q->head->next; 
    struct element *third = second->next;
    
    second->next = third->next;
    if(third ==q->tail){
        q->tail = second;
    }
    free(third);
}

  
void display(queue *q,int n ){
    struct element *curr = q->head;
    for(int i = 0 ; i<n  ; i++){
        city temp = curr->key;
        printf("city = %s \n",temp.name);
        printf("area = %d \n",temp.area);
        printf("inhabitans = %d \n",temp.inhabitans);
        curr=curr->next;
    }    
} 
 
int main() {
    queue q;
    create_queue(&q);
    city temp;
    int n = 4 ;
    for(int i = 0 ; i < n ; i ++){
        printf("city = ");
        scanf("%s",temp.name);
        printf("area = ");
        scanf("%d",&temp.area);
        printf("inhabitans = ");
        scanf("%d",&temp.inhabitans);
        enqueue(&q, temp);
    }
    display(&q,n);
    printf("\n");
    deleteThirdCity(&q);
    display(&q,n-1);

    return 0;
}
