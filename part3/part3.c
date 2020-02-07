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
            Set_free(dstSet);
        }
        DFA_set_accepting(dfa, src-1, NFA_get_accepting(nfa, set));

        Set_free(set);
    }

    return dfa;
}

void NFAtoDFA_print(NFA nfa, DFA dfa) {
    char line[256];
    while (true) {
        printf("\tEnter input (\"quit\" to quit): ");
        fgets(line, 256, stdin);
        line[strlen(line)-1] = '\0'; // Remove \n
        if (strcmp(line, "quit") == 0) break;
        bool answerNFA = NFA_execute(nfa, line);
        bool answerDFA = DFA_execute(dfa, line);
        printf("\t-> Result for input \"%s\" with NFA: %s\n", line, (answerNFA) ? "true" : "false");
        printf("\t-> Result for input \"%s\" with DFA: %s\n", line, (answerDFA) ? "true" : "false");
    }
    printf("\n");
}