#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define NUM_STATES 2
int transitions[NUM_STATES][2] = {
    {-1, 1},
    {-1, 1}
};
bool simulateNFA(const char* str) {
    int currentState = 0;
    for (int i = 0; i < strlen(str); i++) {
        char input = str[i];
        if (input >= '0' && input <= '1') {
            currentState = transitions[currentState][input - '0'];
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
        printf("The string \"%s\" belongs to the language (starts and ends with '1').\n", str);
    } else {
        printf("The string \"%s\" does not belong to the language (starts and ends with '1').\n", str);
    }   
    return 0;
}