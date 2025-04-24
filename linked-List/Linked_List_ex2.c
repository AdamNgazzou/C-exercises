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

void remove_first(struct node **head) {
    if (*head == NULL) return;
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void remove_element_successor(struct node *n) {
    if (n == NULL || n->next == NULL) return;
    struct node *temp = n->next;
    n->next = temp->next;
    free(temp);
}

void delete_value(struct node **head, int value) {
    struct node *curr = *head;
    struct node *before = NULL;
    while (curr != NULL) {
        if (curr->key == value) {
            if (before == NULL) {
                // Delete head node
                remove_first(head);
            } else {
                remove_element_successor(before);
            }
            return; // remove only the first occurrence
        }
        before = curr;
        curr = curr->next;
    }
}

struct node *search(struct node *head, int value){
    struct node *curr = head; 
    while(curr != NULL){
        if(curr->key == value) return curr;
        curr = curr->next; 
    }
    return NULL ;
}

void display(struct list *l) {
    struct node *curr = l->first;
    while (curr != NULL) {
        printf("%d -> ", curr->key);
        curr = curr->next;
    }
    printf("NULL\n");
}

int count_nodes(struct node *head){
    struct node *curr = head; 
    int count = 0 ; 
    while (curr != NULL){
        count ++ ;
        curr = curr -> next ;
    }
    return count;
}

int main() {
    struct list myList;
    create_list(&myList);

    int value;
    printf("Enter 5 integers to insert at the end of the list:\n");
    for (int i = 0; i < 5; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        insert_after_last(&myList, value);
    }

    printf("\nList after inserting 5 elements:\n");
    display(&myList);

    // Insert at beginning
    int insertFirstValue = 100;
    printf("\nInserting %d at the beginning of the list.\n", insertFirstValue);
    insert_before_first(&myList, insertFirstValue);
    display(&myList);

    // Insert at end
    int insertLastValue = 200;
    printf("\nInserting %d at the end of the list.\n", insertLastValue);
    insert_after_last(&myList, insertLastValue);
    display(&myList);

    // Search for values
    int searchExists = value;  // the last value user entered
    int searchNotExists = -1;

    printf("\nSearching for existing value (%d):\n", searchExists);
    struct node *found = search(myList.first, searchExists);
    if (found != NULL)
        printf("Value %d found at address %p.\n", searchExists, (void*)found);
    else
        printf("Value %d not found.\n", searchExists);

    printf("\nSearching for non-existing value (%d):\n", searchNotExists);
    found = search(myList.first, searchNotExists);
    if (found != NULL)
        printf("Value %d found at address %p.\n", searchNotExists, (void*)found);
    else
        printf("Value %d not found.\n", searchNotExists);

    // Delete a value (first occurrence)
    int deleteVal;
    printf("\nEnter a value to delete from the list (only first occurrence will be removed): ");
    scanf("%d", &deleteVal);
    delete_value(&myList.first, deleteVal);
    // If list became empty after deletion, update the 'last' pointer
    if (myList.first == NULL)
        myList.last = NULL;

    printf("\nList after deletion:\n");
    display(&myList);

    printf("\nNumber fo nodes in the list is %d:\n",count_nodes(myList.first));

    return 0;
}
