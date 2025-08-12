// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct node {
    int key ;
    struct node *next;
};
struct list {
    struct node *first ; 
    struct node *last ;
};

void create_list(struct list *l){
    l->first = NULL ;
    l->last = NULL;
}

unsigned isEmpty(struct list l){
    return ((l.first == NULL) && (l.last == NULL)) ;
}

void insert_after(struct node *n, int info){
    struct node *q ;
    q = (struct node * )malloc(sizeof(struct node));
    q -> key = info ;
    q ->next = n ->next;
    n->next = q ;
}

void insert_before(struct node *n, int info) {
    struct node *q = (struct node *)malloc(sizeof(struct node));
    *q = *n; // Copy current node's data and link to q
    n->key = info;
    n->next = q;
}

void insert_before_first(struct list *l, int info){
    struct node *q = (struct node*)malloc(sizeof(struct node));
    q->key = info;
    q->next = l->first;
    l->first = q;
    if (l->last == NULL) {
        l->last = q;
    }
}
void insert_after_last(struct list *l, int info) {
    struct node *q = (struct node *)malloc(sizeof(struct node));
    q->key = info;
    q->next = NULL;
    if (l->last == NULL) {
        l->first = l->last = q;
    } else {
        l->last->next = q;
        l->last = q;
    }
}

void print_list(struct list *l) {
    struct node *curr = l->first;
    while (curr != NULL) {
        printf("%d -> ", curr->key);
        curr = curr->next;
    }
    printf("NULL\n");
}

void remove_element_successor(struct node *n) {
    if (n == NULL || n->next == NULL) return;  // nothing to remove

    struct node *temp = n->next;
    n->next = temp->next;
    free(temp);
}

void remove_first_element(struct list *l){
    if (l->first == NULL) return;  // Add this check
    struct node *temp = l->first ;
    l->first = temp->next ;
    free(temp);
    
}
int main() {
    struct list l;
    create_list(&l);

    printf("List initially empty? %s\n", isEmpty(l) ? "Yes" : "No");

    // Insert elements at the end
    insert_after_last(&l, 10);
    insert_after_last(&l, 20);
    insert_after_last(&l, 30);
    printf("After inserting at the end:\n");
    print_list(&l);

    // Insert before the first
    insert_before_first(&l, 5);
    printf("After inserting before the first element:\n");
    print_list(&l);

    // Insert after second node
    if (l.first != NULL && l.first->next != NULL) {
        insert_after(l.first->next, 25); // insert after node with value 10
        printf("After inserting 25 after second node:\n");
        print_list(&l);
    }

    // Insert before second node
    if (l.first != NULL && l.first->next != NULL) {
        insert_before(l.first->next, 15); // insert before node with value 10
        printf("After inserting 15 before second node:\n");
        print_list(&l);
    }

    // Remove successor of the third node
    if (l.first != NULL && l.first->next != NULL && l.first->next->next != NULL) {
        remove_element_successor(l.first->next->next); // remove successor of 15
        printf("After removing successor of the third node:\n");
        print_list(&l);
    }

    // Remove the first element
    remove_first_element(&l);
    printf("After removing the first element:\n");
    print_list(&l);

    return 0;
}
