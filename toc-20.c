#include <stdio.h>
#include <string.h>0
int parseA(const char *str, int *index, int len);
int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);
    int index = 0;
    int length = strlen(input);
    if (parseA(input, &index, length) && index == length) {
        printf("The string belongs to the language defined by the CFG.\n");
    } else {
        printf("The string does not belong to the language defined by the CFG.\n");
    }
    return 0;
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