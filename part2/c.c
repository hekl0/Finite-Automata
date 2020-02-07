#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "part2.h"

static Set createDstSet(int dst1, int dst2) {
    Set set = new_Set(0);
    Set_insert(set, dst1);
    Set_insert(set, dst2);
    Set_free(set);
    return set;
}

NFA part2_c() {
    // Initialization
    NFA nfa = new_NFA(12);
    for (int i = 0; i < NFA_get_size(nfa); i++) {
        NFA_add_transition_all(nfa, i, createDstSet(i, i));
        NFA_set_accepting(nfa, i, false);
    }
    NFA_add_transition(nfa, 0, 'a', createDstSet(1, 0));
    NFA_add_transition(nfa, 0, 'g', createDstSet(2, 0));
    NFA_add_transition(nfa, 0, 'h', createDstSet(3, 0));
    NFA_add_transition(nfa, 0, 'i', createDstSet(4, 0));
    NFA_add_transition(nfa, 0, 'o', createDstSet(5, 0));
    NFA_add_transition(nfa, 0, 's', createDstSet(6, 0));
    NFA_add_transition(nfa, 0, 't', createDstSet(7, 0));
    NFA_add_transition(nfa, 0, 'w', createDstSet(8, 0));
    NFA_add_transition(nfa, 0, 'n', createDstSet(9, 0));

    NFA_add_transition(nfa, 1, 'a', createDstSet(11, 0));
    NFA_add_transition(nfa, 2, 'g', createDstSet(11, 0));
    NFA_add_transition(nfa, 3, 'h', createDstSet(11, 0));
    NFA_add_transition(nfa, 4, 'i', createDstSet(11, 0));
    NFA_add_transition(nfa, 5, 'o', createDstSet(11, 0));
    NFA_add_transition(nfa, 6, 's', createDstSet(11, 0));
    NFA_add_transition(nfa, 7, 't', createDstSet(11, 0));
    NFA_add_transition(nfa, 8, 'w', createDstSet(11, 0));
    NFA_add_transition(nfa, 9, 'n', createDstSet(10, 0));
    NFA_add_transition(nfa, 10, 'n', createDstSet(11, 0));

    NFA_set_accepting(nfa, 11, true);
    
    printf("Testing NFA that recognizes Strings with more than one a, g, h, i, o, s, t, or w, or more than two n’s :\n");

    return nfa;
}