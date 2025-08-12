/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    struct ListNode* temp = list1;
    struct ListNode* dummy = list1;

    for(int i = 0 ; i<a-1 ; i++){
        dummy = dummy->next;
    }
    temp = dummy;
    for(int i = 0; i<b-a+1 ; i++){
        temp = temp->next; 
    }
    
    dummy->next = list2;
    while(list2->next !=NULL){
        list2 = list2->next;
    }
    list2->next = temp->next;
    return list1;
}
