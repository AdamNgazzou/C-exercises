struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {

    struct ListNode dummy;
    dummy.next = head;
    
    struct ListNode* fast = &dummy;
    struct ListNode* slow = &dummy;

    // Move fast ahead by n + 1 steps to maintain a gap of n
    for (int i = 0; i <= n; i++) {
        if (fast != NULL)
            fast = fast->next;
    }

    // Move both pointers
    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    // Remove the nth node from end
    struct ListNode* toDelete = slow->next;
    slow->next = slow->next->next;
    free(toDelete);

    return dummy.next;
}
