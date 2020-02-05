#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../dfa.h"

DFA part1_a() {
    // Initialization
    DFA dfa = new_DFA(10);
    for (int i = 0; i < DFA_get_size(dfa); i++) {
        DFA_set_transition_all(dfa, i, 9);
        DFA_set_accepting(dfa, i, false);
    }
    DFA_set_transition(dfa, 0, 'c', 1);
    DFA_set_transition(dfa, 1, 'o', 2);
    DFA_set_transition(dfa, 2, 'm', 3);
    DFA_set_transition(dfa, 3, 'p', 4);
    DFA_set_transition(dfa, 4, 'u', 5);
    DFA_set_transition(dfa, 5, 't', 6);    
    DFA_set_transition(dfa, 6, 'e', 7);    
    DFA_set_transition(dfa, 7, 'r', 8); 
    DFA_set_accepting(dfa, 8, true);
    
    printf("Testing DFA that recognizes exactly \"computer\":\n");

    return dfa;
}