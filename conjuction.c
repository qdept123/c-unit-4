#include <stdio.h>

int main() {
    int A, B;

    // Print header with proper formatting
    printf("+---+---+-----------+----------+------------+--------------+\n");
    printf("| A | B | A AND B   | A OR B   | A => B     | A <=> B      |\n");
    printf("+---+---+-----------+----------+------------+--------------+\n");

    for (A = 0; A <= 1; A++) {
        for (B = 0; B <= 1; B++) {
            int and_result = A && B;
            int or_result = A || B;
            int implication = (!A) || B; // A => B
            int biconditional = (A && B) || (!A && !B); // A <=> B

            // Print each row with values
            printf("| %d | %d |     %d     |    %d     |     %d      |      %d       |\n",
                   A, B, and_result, or_result, implication, biconditional);
        }
    }

    printf("+---+---+-----------+----------+------------+--------------+\n");
    return 0;
}
