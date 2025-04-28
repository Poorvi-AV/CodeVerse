/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *p=NULL ; 
    struct ListNode *n=NULL;
    while(head!=NULL){
        n = head ->next;
        head->next=p;
        p=head;
        head=n;

    }
    head=p;
    return head;
}