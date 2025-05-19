/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *prev = dummy, *cur = head;
    while(cur!=NULL){
        if(cur->val==val){
            prev->next=cur->next;
            free(cur);
        }
        else{ 
        prev=cur;
        }
        cur=prev->next;
    }
    head = dummy->next;
    free(dummy);
    return head;
}