#include <stdio.h>

int main() {
    int A;

    printf("+---+----------+--------------+\n");
    printf("| A | A OR ~A  | A AND ~A     |\n");
    printf("+---+----------+--------------+\n");

    int tautology = 1;
    int contradiction = 1;

    for (A = 0; A <= 1; A++) {
        int notA = !A;
        int or_result = A || notA;     // A ∨ ¬A
        int and_result = A && notA;    // A ∧ ¬A

        // Print the row
        printf("| %d |    %d     |      %d       |\n", A, or_result, and_result);

        // Check if it's not tautology or contradiction
        if (or_result == 0)
            tautology = 0;
        if (and_result == 1)
            contradiction = 0;
    }

    printf("+---+----------+--------------+\n");

    // Final result
    if (tautology)
        printf("The expression (A OR NOT A) is a TAUTOLOGY.\n");
    else
        printf("The expression (A OR NOT A) is NOT a tautology.\n");

    if (contradiction)
        printf("The expression (A AND NOT A) is a CONTRADICTION.\n");
    else
        printf("The expression (A AND NOT A) is NOT a contradiction.\n");

    return 0;
}
