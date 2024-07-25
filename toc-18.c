#include <stdio.h>
#include <string.h>
#define MAX_STATES 100
#define MAX_LEN 100
typedef struct {
    int numStates;
    int transitions[MAX_STATES][2]; // Transitions for 0 and 1
} NFA;
void initializeNFA(NFA *nfa, int numStates) {
    nfa->numStates = numStates;
    for (int i = 0; i < numStates; i++) {
        nfa->transitions[i][0] = -1;
        nfa->transitions[i][1] = -1;
    }
}
void addTransition(NFA *nfa, int fromState, int toState, char symbol) {
    if (symbol == '0') {
        nfa->transitions[fromState][0] = toState;
    } else if (symbol == '1') {
        nfa->transitions[fromState][1] = toState;
    }
}
int simulateNFA(const char *input, NFA *nfa) {
    int currentState = 0;
    int length = strlen(input);
    for (int i = 0; i < length; i++) {
        char symbol = input[i];
        if (symbol != '0' && symbol != '1') {
            return 0;
        }
        int nextState = -1;
        if (symbol == '0') {
            nextState = nfa->transitions[currentState][0];
        } else if (symbol == '1') {
            nextState = nfa->transitions[currentState][1];
        }
        if (nextState == -1) {
            return 0;
        }
        currentState = nextState;
    }
    return currentState == 1;
}
int main() {
    NFA nfa;
    initializeNFA(&nfa, 2);
    addTransition(&nfa, 0, 0, '0');
    addTransition(&nfa, 0, 1, '0');
    addTransition(&nfa, 1, 1, '1');
    char input[MAX_LEN];
    printf("Enter a string of 0's and 1's: ");
    scanf("%s", input);
    if (simulateNFA(input, &nfa)) {
        printf("The string is accepted by the NFA.\n");
    } else {
        printf("The string is not accepted by the NFA.\n");
    }
    return 0;
}