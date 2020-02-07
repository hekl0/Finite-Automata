#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "nfa.h"

#define MAX_STATE 64
#define MAX_TRANSITION 128

struct NFA {
    int countState;
    int countInput;
    Set transition[MAX_STATE][MAX_TRANSITION];
    Set initialSetState;
    bool stateAccepted[MAX_STATE];
};

NFA new_NFA(int nstates) {
    NFA nfa = malloc(sizeof(struct NFA));
    nfa->countState = nstates;
    nfa->countInput = MAX_TRANSITION;
    nfa->initialSetState = new_Set(nstates);
    Set_insert(nfa->initialSetState, 0);
    return nfa;
}

void NFA_free(NFA nfa) {
    Set_free(nfa->initialSetState);
    free(nfa);
}

int NFA_get_size(NFA nfa) {
    return nfa->countState;
}

Set NFA_get_transitions(NFA nfa, Set setState, char sym) {
    Set newState = new_Set(NFA_get_size(nfa));
    for (int i = 0; i < NFA_get_size(nfa); i++)
        if (BitSet_lookup(setState, i))
            Set_union(newState, nfa->transition[i][(unsigned char) sym]);
    return newState;
}

void NFA_add_transition(NFA nfa, int src, char sym, Set dst) {
    nfa->transition[src][(unsigned char) sym] = dst;
}

void NFA_add_transition_str(NFA nfa, int src, char *str, int dst) {
    // ????
}

void NFA_add_transition_all(NFA nfa, int src, Set dst) {
    for (int i = 0; i < nfa->countInput; i++)
        nfa->transition[src][i] = dst;
}

void NFA_set_accepting(NFA nfa, int state, bool value) {
    nfa->stateAccepted[state] = value;
}

bool NFA_get_accepting(NFA nfa, Set setState) {
    for (int i = 0; i < NFA_get_size(nfa); i++)
        if (BitSet_lookup(setState, i))
            if (nfa->stateAccepted[i])
                return true;
    return false;
}

bool NFA_execute(NFA nfa, char *input) {
    Set currentSetState = nfa->initialSetState;
    for (int i = 0; i < strlen(input); i++) 
        currentSetState = NFA_get_transitions(nfa, currentSetState, input[i]);
    return NFA_get_accepting(nfa, currentSetState);
}

void NFA_print(NFA nfa) {
    // // ???????????????????
    // printf("NFA with %d states\n", nfa->countState);
    char line[256];
    while (true) {
        printf("\tEnter input (\"quit\" to quit): ");
        fgets(line, 256, stdin);
        line[strlen(line)-1] = '\0'; // Remove \n
        if (strcmp(line, "quit") == 0) break;
        bool answer = NFA_execute(nfa, line);
        printf("\t-> Result for input \"%s\": %s\n", line, (answer) ? "true" : "false");
    }
    printf("\n");
}
