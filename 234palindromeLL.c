/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode *slow=head, *fast=head,*prev=NULL,*temp=NULL;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    while(slow!=NULL){
        temp=slow->next;
        slow->next=prev;
        prev=slow;
        slow=temp;
    }
    struct ListNode *left=head,*right=prev;
    while (right!=NULL){
        if(left->val!=right->val)
          return false;
        left=left->next;
        right=right->next;
    }
    return true;
}