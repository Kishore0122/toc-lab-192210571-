#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool checkS(const char* str, int start, int end) {
    if (start > end) {
        return true;
    }
    if (str[start] == 'a') {
        return checkS(str, start + 1, end);
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