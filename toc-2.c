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
                if (c == '0') {
                    currentState = q1;
                } else {
                    currentState = q_reject;
                }
                break;
            case q1:
                if (c == '1') {
                    currentState = q2;
                }
                // Any other character, stay in q1
                break;
            case q2:
                // Once we are in q2, we stay in q2
                break;
            case q_reject:
                return false; // Already rejected
        }
    }
    
    // Check if we ended in the accepting state
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
