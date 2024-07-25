#include <stdio.h>
#include <stdbool.h>
#include <string.h>
typedef enum {
    q0, q1, q2, q_reject
} State;
bool isAccepted(char *str) {
    State currentState = q0;
    int i;
    for (i = 0; i < strlen(str); i++) {
        char c = str[i];
        switch (currentState) {
            case q0:
                if (c == 'a') {
                    currentState = q1;
                } else {
                    currentState = q_reject;
                }
                break;
            case q1:
                if (c == 'a') {
                    currentState = q2;
                }
                break;
            case q2:
                break;
            case q_reject:
                return false;
        }
    }
    return currentState == q2;
}
int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    if (isAccepted(str)) {
        printf("The string is accepted by the DFA.\n");
    } else {
        printf("The string is rejected by the DFA.\n");
    }   
    return 0;
}