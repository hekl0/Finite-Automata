#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../dfa.h"

DFA part1_c() {
    // Initialization
    DFA dfa = new_DFA(3);
    for (int i = 0; i < DFA_get_size(dfa); i++) {
        DFA_set_transition_all(dfa, i, 2);
        DFA_set_accepting(dfa, i, false);
    }
    DFA_set_transition(dfa, 0, '0', 1);
    DFA_set_transition(dfa, 0, '1', 0);
    DFA_set_transition(dfa, 1, '0', 0);
    DFA_set_transition(dfa, 1, '1', 1);
    DFA_set_accepting(dfa, 1, true);
    
    printf("Testing DFA that recognizes Binary input with an odd number of 0’s:\n");

    return dfa;
}