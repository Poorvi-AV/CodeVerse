#include<stdio.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
void swap(struct ListNode **a, struct ListNode **b) {
    struct ListNode *temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyDown(struct ListNode **heap, int size, int i) {
    int smallest = i;
    int left = 2 * i + 1, right = 2 * i + 2;

    if (left < size && heap[left]->val < heap[smallest]->val)
        smallest = left;

    if (right < size && heap[right]->val < heap[smallest]->val)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

void heapifyUp(struct ListNode **heap, int i) {
    if (i == 0) return;
    int parent = (i - 1) / 2;

    if (heap[i]->val < heap[parent]->val) {
        swap(&heap[i], &heap[parent]);
        heapifyUp(heap, parent);
    }
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) return NULL;

    struct ListNode **heap = malloc(sizeof(struct ListNode*) * listsSize);
    int heapSize = 0;

   
    for (int i = 0; i < listsSize; i++) {
        if (lists[i]) {
            heap[heapSize++] = lists[i];
            heapifyUp(heap, heapSize - 1);
        }
    }

    struct ListNode dummy;
    struct ListNode *tail = &dummy;
    dummy.next = NULL;

    while (heapSize > 0) {
        struct ListNode *minNode = heap[0];

        
        tail->next = minNode;
        tail = tail->next;

        if (minNode->next) {
            heap[0] = minNode->next;
        } else {
            heap[0] = heap[--heapSize]; 
        }

        heapifyDown(heap, heapSize, 0);
    }

    free(heap);
    return dummy.next;
}



