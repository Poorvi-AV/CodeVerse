


typedef struct {
    int *queue;
    int front , rear ;
    int size;
} MyStack;


MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->size = 100; 
    stack->queue = malloc(stack->size * sizeof(int));
    stack->front = stack->rear = 0;
    return stack;
}

void myStackPush(MyStack* obj, int x) {
   obj->queue[obj->rear++] = x;
}

int myStackPop(MyStack* obj) {
    return obj->queue[--obj->rear];
}

int myStackTop(MyStack* obj) {
    return obj->queue[obj->rear - 1];
}

bool myStackEmpty(MyStack* obj) {
    return obj->rear == 0;
}

void myStackFree(MyStack* obj) {
    free(obj->queue);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/