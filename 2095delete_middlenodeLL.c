/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {
    int count=0;
    if(head==NULL)
    {printf("LL empty"); return head;} 
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct ListNode *ptr = NULL,*ptr2=NULL;
    ptr=head;
    while(ptr!=NULL){
        count++; 
        ptr=ptr->next;
    }
    int mid=count/2+1;
    ptr=head;
    int i=1;
    while(i!=mid){
        ptr2=ptr;
        ptr=ptr->next;
        i++;
    }
    ptr2->next=ptr->next;
    free(ptr);

    return head;
}