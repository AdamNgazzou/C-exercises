#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int key;
    struct node* next;
};

// Define the list structure
typedef struct {
    struct node* first;
    struct node* last;
} List;

// Create an empty list
List createList() {
    List l1;
    l1.first = NULL;
    l1.last = NULL;
    return l1;
}

// Check if the list is empty
int isEmpty(List l) {
    return ((l.first == NULL) && (l.last == NULL));
}

// Display the list
void display(List l) {
    struct node* curr = l.first;
    while (curr != NULL) {
        printf("%d -> ", curr->key);
        curr = curr->next;
    }
    printf("NULL\n");
}

// Insert a node at the end (helper for testing)
void insert_end(List* l, int val) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->key = val;
    new_node->next = NULL;
    
    if (isEmpty(*l)) {
        l->first = new_node;
        l->last = new_node;
    } else {
        l->last->next = new_node;
        l->last = new_node;
    }
}

// 🔧 Insert val after each node
void insert_val_after(List* l, int val) {
    struct node* curr = l->first;
    while (curr != NULL) {
        // Create the new node with the value to insert
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->key = val;
        new_node->next = curr->next;
        
        // Insert the new node after current
        curr->next = new_node;

        // Move to the node after the inserted node
        curr = new_node->next;

        // Update last if needed
        if (new_node->next == NULL) {
            l->last = new_node;
        }
    }
}
void add_sort(List *l, int x) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->key = x;
    new_node->next = NULL;

    // Case 1: Empty list
    if (l->first == NULL) {
        l->first = new_node;
        l->last = new_node;
        return;
    }

    // Case 2: Insert at the beginning
    if (x < l->first->key) {
        new_node->next = l->first;
        l->first = new_node;
        return;
    }

    // Traverse to find correct position
    struct node* curr = l->first;
    while (curr->next != NULL && curr->next->key < x) {
        curr = curr->next;
    }

    // Insert in the middle or at the end
    new_node->next = curr->next;
    curr->next = new_node;

    // Update last if inserted at the end
    if (new_node->next == NULL) {
        l->last = new_node;
    }
}

void delete_after(List* l) {
    if (!l || !l->first || !l->first->next) return;

    struct node* current = l->first->next; // Start at position 2 (second node)
    while (current && current->next) {
        struct node* temp = current->next;         // Node to be deleted
        current->next = temp->next;         // Bypass the deleted node
        free(temp);                         // Free memory

        if (current->next)                  // Move to the next 'survivor'
            current = current->next;
        else
            break;
    }
}

void delete_max(List *l) {
    if (l == NULL || l->first == NULL)
        return; // Empty list

    struct node *curr = l->first;
    struct node *max_node = l->first;
    struct node *prev_max = NULL;

    while (curr->next != NULL) {
        if (curr->next->key > max_node->key) {
            prev_max = curr;
            max_node = curr->next;
        }
        curr = curr->next;
    }

    // If max_node is the first node
    if (max_node == l->first) {
        l->first = max_node->next;
        if (l->first == NULL) // list became empty
            l->last = NULL;
    } else {
        prev_max->next = max_node->next;
        if (max_node == l->last) // deleted last node
            l->last = prev_max;
    }

    free(max_node);
}

void Merge (List l1, List l2, List *l3){
    struct node* p1 = l1.first;
    struct node* p2 = l2.first;
    int lastInserted = -1e9; 

    while (p1 != NULL && p2 != NULL) {
        if (p1->key < p2->key) {
            if(p1->key != lastInserted){
                add_sort(l3,p1->key);
                lastInserted = p1->key;
            }
            p1 = p1->next;
        }else if(p1->key > p2->key){
            if(p2->key != lastInserted){
                add_sort(l3,p2->key);
                lastInserted = p2->key;
            }
            p2 = p2->next;    
        }else{
            if(p1->key != lastInserted){
                add_sort(l3,p1->key);
                lastInserted = p1->key;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    
    // Add remaining nodes from l1
    while (p1 != NULL) {
        if (p1->key != lastInserted) {
            add_sort(l3, p1->key);
            lastInserted = p1->key;
        }
        p1 = p1->next;
    }

    // Add remaining nodes from l2
    while (p2 != NULL) {
        if (p2->key != lastInserted) {
            add_sort(l3, p2->key);
            lastInserted = p2->key;
        }
        p2 = p2->next;
    }

}
// Test the function
int main() {
    // Test insert_end and display
    List list1 = createList();
    insert_end(&list1, 10);
    insert_end(&list1, 20);
    insert_end(&list1, 30);
    printf("List1 after insert_end:\n");
    display(list1);

    // Test insert_val_after
    insert_val_after(&list1, 0);
    printf("\nList1 after inserting 0 after each element:\n");
    display(list1);

    // Test delete_after
    delete_after(&list1);
    printf("\nList1 after deleting every node after the first, third, etc.:\n");
    display(list1);

    // Test delete_max
    delete_max(&list1);
    printf("\nList1 after deleting the max element:\n");
    display(list1);

    // Test add_sort
    List list2 = createList();
    add_sort(&list2, 15);
    add_sort(&list2, 5);
    add_sort(&list2, 25);
    add_sort(&list2, 20);
    printf("\nList2 after add_sort:\n");
    display(list2);

    // Test Merge
    List mergedList = createList();
    Merge(list1, list2, &mergedList);
    printf("\nMerged list of list1 and list2 (sorted and no duplicates):\n");
    display(mergedList);

    return 0;
}
