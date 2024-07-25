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
bool checkS(const char* str, int start, int end) {
    if (start > end) {
        return true;
    }
    if (end - start >= 2 && strncmp(str + start, "101", 3) == 0) {
        return checkA(str, start, end);
    }   
    return false;
}
int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    if (checkS(str, 0, strlen(str) - 1)) {
        printf("The string belongs to the language defined by the CFG.\n");
    } else {
        printf("The string does not belong to the language defined by the CFG.\n");
    }   
    return 0;
}