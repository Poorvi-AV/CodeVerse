char* removeKdigits(char* num, int k) {
    int n = strlen(num);
    char* stack = (char*)malloc(sizeof(char) * (n + 1));
    int top = -1;

    for (int i = 0; i < n; i++) {
        while (top >= 0 && stack[top] > num[i] && k > 0) {
            top--; 
            k--;
        }
        stack[++top] = num[i]; 
    }

   
    top -= k;

    int idx = 0;
    while (idx <= top && stack[idx] == '0') {
        idx++;
    }

    if (idx > top) {
        return strdup("0");
    }

    stack[top + 1] = '\0'; 
    return strdup(stack + idx);
}
