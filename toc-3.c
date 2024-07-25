#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool checkA(const char* str, int start, int end) {
    if (start > end) {
        return true;
    }
    
    if ((str[start] == '0' || str[start] == '1') && checkA(str, start + 1, end)) {
        return true;
    }
    
    return false;
}

bool checkS(const char* str) {
    int len = strlen(str);
    
    if (len < 2) {
        return false;
    }
    
    if (str[0] == '0' && str[len - 1] == '1') {
        return checkA(str, 1, len - 2);
    }
    
    return false;
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    scanf("%s", str);
    
    if (checkS(str)) {
        printf("The string belongs to the language defined by the CFG.\n");
    } else {
        printf("The string does not belong to the language defined by the CFG.\n");
    }
    
    return 0;
}
