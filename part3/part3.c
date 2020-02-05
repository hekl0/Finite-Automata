#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "part3.h"

DFA convertNFAtoDFA(NFA nfa) {
    DFA dfa = new_DFA(1LL << NFA_get_size(nfa));

    for (unsigned long long int src = 1; src < DFA_get_size(dfa); src++) {
        Set set = new_BitSetFromValue(src);

        for (int sym = 0; sym < 128; sym++) {
            Set dstSet = NFA_get_transitions(nfa, set, sym);
            unsigned long long int dst = Bitset_toInt(dstSet);
            DFA_set_transition(dfa, src-1, sym, dst-1);
        }
        DFA_set_accepting(dfa, src-1, NFA_get_accepting(nfa, set));

        Set_free(set);
    }

    return dfa;
}