#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dfa.h"

#define MAX_STATE 100
#define MAX_TRANSITION 128

struct DFA {
    int countState;
    int countInput;
    int transition[MAX_STATE][MAX_TRANSITION];
    int initialState;
    bool stateAccepted[MAX_STATE];
};

DFA new_DFA(int nstates) {
    DFA dfa = malloc(sizeof(struct DFA));
    dfa->countState = nstates;
    dfa->countInput = MAX_TRANSITION;
    dfa->initialState = 0;
    return dfa;
}

void DFA_free(DFA dfa) {
    free(dfa->transition);
    free(dfa->stateAccepted);
    free(dfa);
}

int DFA_get_size(DFA dfa) {
    return dfa->countState;
}

int DFA_get_transition(DFA dfa, int src, char sym) {
    return dfa->transition[src][(unsigned char) sym];
}

void DFA_set_transition(DFA dfa, int src, char sym, int dst) {
    dfa->transition[src][(unsigned char) sym] = dst;
}

void DFA_set_transition_str(DFA dfa, int src, char *str, int dst) {
    // ??????????????
}

void DFA_set_transition_all(DFA dfa, int src, int dst) {
    for (int i = 0; i < dfa->countInput; i++)
        dfa->transition[src][i] = dst;
}

void DFA_set_accepting(DFA dfa, int state, bool value) {
    dfa->stateAccepted[state] = value;
} 

bool DFA_get_accepting(DFA dfa, int state) {
    return dfa->stateAccepted[state];
}

bool DFA_execute(DFA dfa, char *input) {
    int currentState = dfa->initialState;
    for (int i = 0; i < strlen(input); i++) 
        currentState = DFA_get_transition(dfa, currentState, input[i]);
    return DFA_get_accepting(dfa, currentState);
}

void DFA_print(DFA dfa) {
    // ???????????????????
    printf("DFA with %d states\n", dfa->countState);
}