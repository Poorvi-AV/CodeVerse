#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
bool isValid(char* s) {
    int len = strlen(s);
    char* stack = (char*)malloc(sizeof(char) * len);
    int top = -1;

    for (int i = 0; i < len; i++) {
        char ch = s[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            stack[++top] = ch;
        } else {
            if (top == -1) {
                free(stack);
                return false; 
            }
            char open = stack[top--];
            if ((ch == ')' && open != '(') ||
                (ch == ']' && open != '[') ||
                (ch == '}' && open != '{')) {
                free(stack);
                return false;
            }
        }
    }

    bool result = (top == -1); 
    free(stack);
    return result;
}
