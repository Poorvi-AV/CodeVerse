#define MAX_SIZE 1000
char* simplifyPath(char* path) {
    char* stack[MAX_SIZE];  
    int top = -1;
    
    char* token = strtok(path, "/");  
    
    while (token != NULL) {
        if (strcmp(token, "..") == 0) {
            if (top >= 0) top--;  
        } else if (strcmp(token, ".") != 0 && strlen(token) > 0) {
            stack[++top] = token;  
        }
        token = strtok(NULL, "/");
    }

   
    char* result = (char*)malloc(MAX_SIZE);
    strcpy(result, "/");
    
    for (int i = 0; i <= top; i++) {
        strcat(result, stack[i]);
        if (i < top) strcat(result, "/");  
    }
    
    return result; 
}
