#include <stdio.h>
#include <stdlib.h>

#include "dfa.h"
#include "part1/a.c"
#include "part1/b.c"
#include "part1/c.c"
#include "part1/d.c"
#include "part1/e.c"

#include "part2/part2.h"

#include "part3/part3.h"

void testPart1() {
    DFA dfa;
    DFA (*func_p1[5])() = {part1_a, part1_b, part1_c, part1_d, part1_e};

    for (int i = 0; i < 5; i++) {
        dfa = (*func_p1[i])();
        DFA_print(dfa);
        DFA_free(dfa);
    }
}

void testPart2() {
    NFA nfa;
    NFA (*func_p2[4])() = {part2_a, part2_b, part2_c, part2_d};

    for (int i = 0; i < 4; i++) {
        nfa = (*func_p2[i])();
        NFA_print(nfa);
        NFA_free(nfa);
    }
}

void testPart3() {
    NFA nfa;
    DFA dfa;
    NFA (*func_p2[4])() = {part2_a, part2_b, part2_c, part2_d};
    for (int i = 0; i < 2; i++) {
        nfa = (*func_p2[i])();
        dfa = convertNFAtoDFA(nfa);
        
        NFAtoDFA_print(nfa, dfa);

        DFA_free(dfa);
        NFA_free(nfa);
    }
}

int main( int argc, char** argv ) {
    printf("\n\t\t-----PART 1-----\n\n");
    testPart1();

    printf("\n\t\t-----PART 2-----\n\n");
    testPart2();

    printf("\n\t\t-----PART 3-----\n\n");
    testPart3();

    return 0;
}
