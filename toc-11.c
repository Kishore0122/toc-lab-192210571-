#include <stdio.h>
#include <stdlib.h>
#define MAX_STATES 100
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
void addEpsilonTransition(NFA *nfa, int fromState, int toState) {
    nfa->transitions[fromState][toState] = 1;
}
void findEpsilonClosure(NFA *nfa, int state, int *closure, int *visited) {
    if (visited[state]) {
        return;
    }
    visited[state] = 1;
    closure[state] = 1;
    for (int i = 0; i < nfa->numStates; i++) {
        if (nfa->transitions[state][i] == 1) {
            findEpsilonClosure(nfa, i, closure, visited);
        }
    }
}
void printEpsilonClosure(NFA *nfa) {
    for (int i = 0; i < nfa->numStates; i++) {
        int closure[MAX_STATES] = {0};
        int visited[MAX_STATES] = {0};
        findEpsilonClosure(nfa, i, closure, visited);
        printf("Epsilon-closure of state %d: { ", i);
        for (int j = 0; j < nfa->numStates; j++) {
            if (closure[j]) {
                printf("%d ", j);
            }
        }
        printf("}\n");
    }
}
int main() {
    int numStates, numTransitions, fromState, toState;
    NFA nfa;
    printf("Enter the number of states: ");
    scanf("%d", &numStates);
    initializeNFA(&nfa, numStates);
    printf("Enter the number of epsilon transitions: ");
    scanf("%d", &numTransitions);
    printf("Enter the epsilon transitions (fromState toState):\n");
    for (int i = 0; i < numTransitions; i++) {
        scanf("%d %d", &fromState, &toState);
        addEpsilonTransition(&nfa, fromState, toState);
    }
    printEpsilonClosure(&nfa);
    return 0;
}