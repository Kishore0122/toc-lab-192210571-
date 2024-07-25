#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define NUM_STATES 2
int transitions[NUM_STATES][2] = {
    {0, 1},
    {-1, -1}
};
bool simulateNFA(const char* str) {
    int currentState = 0;
    for (int i = 0; i < strlen(str); i++) {
        char input = str[i];
        if (input == 'b') {
            currentState = transitions[currentState][0];
        } else if (input == 'a') {
            currentState = transitions[currentState][1];
        } else {
            return false;
        }   
        if (currentState == -1) {
            return false;
        }
    }   
    return currentState == 1;
}
int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    if (simulateNFA(str)) {
        printf("The string \"%s\" belongs to the language (starts with 'b' and ends with 'a').\n", str);
    } else {
        printf("The string \"%s\" does not belong to the language (starts with 'b' and ends with 'a').\n", str);
    }   
    return 0;
}