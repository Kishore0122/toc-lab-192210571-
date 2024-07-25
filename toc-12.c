#include <stdio.h>
#include <string.h>
#define MAX_LEN 100
typedef enum { q0, q1, q2 } State;
State getNextState(State currentState, char input) {
    switch (currentState) {
        case q0:
            if (input == 'b') return q1;
            break;
        case q1:
            if (input == 'a') return q1;
            if (input == 'b') return q2;
            break;
        case q2:
            if (input == 'a') return q1;
            if (input == 'b') return q2;
            break;
    }
    return q0;
}
int simulateDFA(const char *input) {
    State currentState = q0;
    int length = strlen(input);
    for (int i = 0; i < length; i++) {
        currentState = getNextState(currentState, input[i]);
    }
    return currentState == q2;
}
int main() {
    char input[MAX_LEN];
    printf("Enter a string of a's and b's: ");
    scanf("%s", input);
    if (simulateDFA(input)) {
        printf("The string is accepted by the DFA.\n");
    } else {
        printf("The string is not accepted by the DFA.\n");
    }
    return 0;
}