 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* swapPairs(struct ListNode* head) {
    if (!head || !head->next)
        return head;
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;

    while (prev->next != NULL && prev->next->next != NULL) {
        
        struct ListNode* first = prev->next;
        struct ListNode* second = first->next;

        
        first->next = second->next;
        second->next = first;
        prev->next = second;

        
        prev = first;
    }
    return dummy.next;
}
