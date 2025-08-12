/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 //Use two pointers, one for each list. Traverse each list with its pointer. When a pointer reaches the end of its list, redirect it to the head of the other list. If there is an intersection, the pointers will eventually meet at the intersection node after at most m + n steps (where m and n are the lengths of the lists).
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* a = headA;
    struct ListNode* b = headB;

    while (a != b) {
        a = (a == NULL) ? headB : a->next;
        b = (b == NULL) ? headA : b->next;
    }
    return a;  // or return b
}
