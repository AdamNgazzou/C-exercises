/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head ; 
        while (curr != nullptr) {
            // If no child, just move forward
            if (curr->child == nullptr) {
                curr = curr->next;
                continue;
            }
            // Step 1: Save the next node
            Node* next = curr->next;

            // Step 2: Recursively flatten the child list
            Node* childHead = flatten(curr->child); 

            // Step 3: Connect curr <-> childHead
            curr->next = childHead; 
            childHead->prev = curr;

            // Step 4: Go to the tail of the child list
            Node* childTail = childHead;
            while (childTail->next != nullptr) {
                childTail = childTail->next;
            }
            // Step 5: Connect tail of child list to the saved next node
            childTail->next = next;
            if(next) next->prev = childTail;

            // Step 6: Remove the child pointer
            curr->child = nullptr;

            // Step 7: Move to the next node (formerly the childTail->next)
            curr = next; 
        }
        return head;
    }
};
