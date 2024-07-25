#include <stdio.h>
#include <string.h>
int parseA(const char *str, int start, int len);
int parseS(const char *str, int start, int len) {
    int n = len - start;
    if (n < 4) return 0;
    if (str[start + n - 3] != '0' || str[start + n - 2] != '0') return 0;
    for (int mid = start; mid <= start + n - 4; ++mid) {
        if (parseA(str, start, mid - start) && parseA(str, mid + 2, n - (mid - start + 4))) {
            return 1;
        }
    }
    return 0;
}
int parseA(const char *str, int start, int len) {
    int n = len - start;
    if (n == 0) return 1;
    if (str[start] == '0' || str[start] == '1') {
        return parseA(str, start + 1, n - 1);
    }
    return 0;
}
int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);
    int length = strlen(input);
    if (parseS(input, 0, length)) {
        printf("The string belongs to the language defined by the CFG.\n");
    } else {
        printf("The string does not belong to the language defined by the CFG.\n");
    }
    return 0;
}