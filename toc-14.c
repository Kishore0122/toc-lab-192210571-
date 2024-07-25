#include <stdio.h>
#include <string.h>
#define MAX_STATES 100
#define MAX_LEN 100
typedef struct {
    int numStates;
    int transitions[MAX_STATES][MAX_STATES];
} NFA;
void initializeNFA(NFA *nfa, int numStates) {
    nfa->numStates = numStates;
    for (int i = 0; i < numStates; i++) {
        for (int j = 0; j < numStates; j++) {
            nfa->transitions[i][j] = 0;
        }
    }
}
void addTransition(NFA *nfa, int fromState, int toState, char symbol) {
    nfa->transitions[fromState][symbol - 'a' + 1] |= (1 << toState);
}
void simulateNFA(NFA *nfa, const char *input) {
    int currentStates[MAX_STATES] = {0};
    int nextStates[MAX_STATES];
    int length = strlen(input);
    currentStates[0] = 1; // Start state
    for (int i = 0; i < length; i++) {
        memset(nextStates, 0, sizeof(nextStates));
        for (int j = 0; j < nfa->numStates; j++) {
            if (currentStates[j]) {
                int transitions = nfa->transitions[j][input[i] - 'a' + 1];
                for (int k = 0; k < nfa->numStates; k++) {
                    if (transitions & (1 << k)) {
                        nextStates[k] = 1;
                    }
                }
            }
        }
        memcpy(currentStates, nextStates, sizeof(currentStates));
    }
    if (currentStates[2]) {
        printf("The string is accepted by the NFA.\n");
    } else {
        printf("The string is not accepted by the NFA.\n");
    }
}
int main() {
    NFA nfa;
    initializeNFA(&nfa, 3);
    addTransition(&nfa, 0, 1, 'b');
    addTransition(&nfa, 0, 0, 'a');
    addTransition(&nfa, 1, 2, 'a');
    addTransition(&nfa, 1, 1, 'b');
    addTransition(&nfa, 2, 2, 'a');
    addTransition(&nfa, 2, 2, 'b');
    char input[MAX_LEN];
    printf("Enter a string of a's and b's: ");
    scanf("%s", input);
    simulateNFA(&nfa, input);
    return 0;
}