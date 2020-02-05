#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "part2.h"

static Set createDstSet(int dst) {
    Set set = new_Set(0);
    Set_insert(set, dst);
    return set;
}

NFA part2_d() {
    // Initialization
    NFA nfa = new_NFA(1);
    for (int i = 0; i < NFA_get_size(nfa); i++) {
        NFA_add_transition_all(nfa, i, createDstSet(0));
        NFA_set_accepting(nfa, i, false);
    }
    NFA_set_accepting(nfa, 0, true);
    
    printf("Testing NFA that recognizes anything:\n");

    return nfa;
}