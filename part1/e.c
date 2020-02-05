#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../dfa.h"

DFA part1_e() {
    // Initialization
    DFA dfa = new_DFA(1);
    for (int i = 0; i < DFA_get_size(dfa); i++) {
        DFA_set_transition_all(dfa, i, 0);
        DFA_set_accepting(dfa, i, false);
    }
    DFA_set_accepting(dfa, 0, true);
    
    printf("Testing DFA that recognizes anything:\n");

    return dfa;
}