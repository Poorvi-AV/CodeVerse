
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // Create a dummy node to simplify the code
    struct ListNode dummy;
    struct ListNode* current = &dummy;
    int carry = 0;

    // Iterate through both lists
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;
        
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        // Update carry for next iteration
        carry = sum / 10;
        
        // Create a new node with the digit value of sum % 10
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;
        
        // Append the new node to the result list
        current->next = newNode;
        current = current->next;
    }
    
    // Return the next node of dummy, which is the head of the result list
    return dummy.next;
}
