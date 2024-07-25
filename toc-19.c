#include <stdio.h>
#include <string.h>
int parseA(const char *str, int *index, int len);
int parseS(const char *str, int *index, int len) {
    if (*index >= len || str[*index] != 'a') return 0;
    (*index)++;
    if (!parseA(str, index, len)) return 0;
    if (*index >= len || str[*index] != 'a') return 0;
    (*index)++;
    if (!parseA(str, index, len)) return 0;
    if (*index >= len || str[*index] != 'a') return 0;
    (*index)++;
    return 1;
}
int parseA(const char *str, int *index, int len) {
    if (*index >= len) return 1;   
    if (str[*index] == 'a' || str[*index] == 'b') {
        char current = str[*index];
        (*index)++;
        return parseA(str, index, len);
    }
    return 0;
}
int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);
    int index = 0;
    int length = strlen(input);
    if (parseS(input, &index, length) && index == length) {
        printf("The string belongs to the language defined by the CFG.\n");
    } else {
        printf("The string does not belong to the language defined by the CFG.\n");
    }
    return 0;
}