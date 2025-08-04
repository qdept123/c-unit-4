#include <stdio.h>

// Function to calculate factorial
long long factorial(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to calculate nCr
long long combination(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

// Function to calculate nPr
long long permutation(int n, int r) {
    return factorial(n) / factorial(n - r);
}

int main() {
    int n, r;

    printf("Enter values of n and r (n >= r): ");
    scanf("%d %d", &n, &r);

    if (n < r) {
        printf("Invalid input. n should be greater than or equal to r.\n");
    } else {
        printf("nCr (Combination) = %lld\n", combination(n, r));
        printf("nPr (Permutation) = %lld\n", permutation(n, r));
    }

    return 0;
}
