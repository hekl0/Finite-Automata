#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../dfa.h"

DFA part1_b() {
    // Initialization
    DFA dfa = new_DFA(6);
    for (int i = 0; i < DFA_get_size(dfa); i++) {
        DFA_set_transition_all(dfa, i, 5);
        DFA_set_accepting(dfa, i, false);
    }
    DFA_set_transition(dfa, 0, 'r', 1);
    DFA_set_transition(dfa, 1, 'o', 2);
    DFA_set_transition(dfa, 2, 'f', 3);
    DFA_set_transition(dfa, 3, 'l', 4);
    DFA_set_transition_all(dfa, 4, 4);
    DFA_set_accepting(dfa, 4, true);
    
    printf("Testing DFA that recognizes Any string that starts with the characters \"rofl\":\n");

    return dfa;
}