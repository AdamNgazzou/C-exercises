/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* nextTemp = NULL;

    while (curr != NULL) {
        nextTemp = curr->next;   
        curr->next = prev;       
        prev = curr;             
        curr = nextTemp;         
    }

    return prev; 
}
void reorderList(struct ListNode* head) {
        if (head == NULL || head->next == NULL) return;

    // Step 1: Find middle of the list
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse second half
    struct ListNode* firstHalf = head;
    struct ListNode* secondHalf = reverseList(slow->next);
    slow->next = NULL; // Break the list

    
    struct ListNode* temp1;
    struct ListNode* temp2;

    while (secondHalf != NULL) {
        temp1 = firstHalf->next;
        temp2 = secondHalf->next;

        firstHalf->next = secondHalf;
        secondHalf->next = temp1;

        firstHalf = temp1;
        secondHalf = temp2;
    }
}
