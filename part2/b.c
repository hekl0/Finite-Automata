#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "part2.h"

static Set createDstSet(int dst) {
    Set set = new_Set(0);
    Set_insert(set, dst);
    Set_free(set);
    return set;
}

NFA part2_b() {
    // Initialization
    NFA nfa = new_NFA(4);
    for (int i = 0; i < NFA_get_size(nfa); i++) {
        NFA_add_transition_all(nfa, i, createDstSet(0));
        NFA_set_accepting(nfa, i, false);
    }
    NFA_add_transition(nfa, 0, 'e', createDstSet(1));
    NFA_add_transition(nfa, 1, 'm', createDstSet(2));
    NFA_add_transition(nfa, 2, 'b', createDstSet(3));
    NFA_add_transition_all(nfa, 3, createDstSet(3));
    NFA_set_accepting(nfa, 3, true);
    
    printf("Testing NFA that recognizes Strings containing emb :\n");

    return nfa;
}