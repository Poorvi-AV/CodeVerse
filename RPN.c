#define MAX_SIZE 5000  


int stack[MAX_SIZE];
int top = -1;


void push(int num) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow!\n");
        exit(1);
    }
    stack[++top] = num;
}


int pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return stack[top--];
}


int evalRPN(char* tokens[], int tokenSize) {
    for (int i = 0; i < tokenSize; i++) {
        char* token = tokens[i];

     
        if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 ||
            strcmp(token, "*") == 0 || strcmp(token, "/") == 0) {
            
           
            int b = pop();
            int a = pop();

            
            if (strcmp(token, "+") == 0) push(a + b);
            else if (strcmp(token, "-") == 0) push(a - b);
            else if (strcmp(token, "*") == 0) push(a * b);
            else if (strcmp(token, "/") == 0) push(a / b); 
        } else {
           
            push(atoi(token));
        }
    }

    return pop(); 
}

