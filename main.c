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

void testPart1(DFA dfa) {
    char line[256];
    while (true) {
        printf("\tEnter input (\"quit\" to quit): ");
        fgets(line, 256, stdin);
        line[strlen(line)-1] = '\0'; // Remove \n
        if (strcmp(line, "quit") == 0) break;
        bool answer = DFA_execute(dfa, line);
        printf("\t-> Result for input \"%s\": %s\n", line, (answer) ? "true" : "false");
    }
    printf("\n");
}

void testPart2(NFA nfa) {
    char line[256];
    while (true) {
        printf("\tEnter input (\"quit\" to quit): ");
        fgets(line, 256, stdin);
        line[strlen(line)-1] = '\0'; // Remove \n
        if (strcmp(line, "quit") == 0) break;
        bool answer = NFA_execute(nfa, line);
        printf("\t-> Result for input \"%s\": %s\n", line, (answer) ? "true" : "false");
    }
    printf("\n");
}

void testPart3(DFA dfa, NFA nfa) {
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

int main( int argc, char** argv ) {
    printf("\n\t\t-----PART 1-----\n\n");
    DFA dfa;
    DFA (*func_p1[5])() = {part1_a, part1_b, part1_c, part1_d, part1_e};

    for (int i = 0; i < 5; i++) {
        dfa = (*func_p1[i])();
        testPart1(dfa);
    }

    printf("\n\t\t-----PART 2-----\n\n");
    NFA nfa;
    NFA (*func_p2[4])() = {part2_a, part2_b, part2_c, part2_d};

    for (int i = 0; i < 4; i++) {
        nfa = (*func_p2[i])();
        testPart2(nfa);
    }

    printf("\n\t\t-----PART 3-----\n\n");
    for (int i = 0; i < 2; i++) {
        nfa = (*func_p2[i])();
        dfa = convertNFAtoDFA(nfa);

        NFA_print(nfa);
        DFA_print(dfa);

        testPart3(dfa, nfa);
    }

    return 0;
}