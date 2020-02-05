#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../dfa.h"

DFA part1_d() {
    // Initialization
    DFA dfa = new_DFA(5);
    for (int i = 0; i < DFA_get_size(dfa); i++) {
        DFA_set_transition_all(dfa, i, 4);
        DFA_set_accepting(dfa, i, false);
    }
    DFA_set_transition(dfa, 0, '0', 1);
    DFA_set_transition(dfa, 0, '1', 2);
    DFA_set_transition(dfa, 1, '0', 0);
    DFA_set_transition(dfa, 1, '1', 3);
    DFA_set_transition(dfa, 2, '1', 0);
    DFA_set_transition(dfa, 2, '0', 3);
    DFA_set_transition(dfa, 3, '0', 2);
    DFA_set_transition(dfa, 3, '1', 1);
    DFA_set_accepting(dfa, 3, true);
    
    printf("Testing DFA that recognizes Binary input with an odd number of both 0’s and 1’s:\n");

    return dfa;
}