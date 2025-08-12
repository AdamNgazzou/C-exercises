/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return true;
    
    // Step 1: Find the middle
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while(fast->next !=NULL && fast->next->next != NULL){
        fast = fast->next->next ;
        slow = slow->next;
    }

    // Step 2: Reverse second half
    struct ListNode* prev = NULL ;
    struct ListNode* curr = slow->next;
    struct ListNode* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev ;
        prev = curr ;
        curr = next ;
    }

    // Step3: compare both values : 
    struct ListNode* first = head;
    struct ListNode* second = prev;
    while(second != NULL){
        if(first->val != second->val) return false ;
        first = first->next;
        second = second->next;
    }
    return true;
}
