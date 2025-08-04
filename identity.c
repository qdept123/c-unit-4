#include <stdio.h>

// Function to calculate factorial
long long factorial(int n) {
    long long fact = 1;
    for (int i = 2; i <= n; i++) {
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
        printf("Invalid input. n must be greater than or equal to r.\n");
        return 1;
    }

    long long nCr = combination(n, r);
    long long rFact = factorial(r);
    long long nPr = permutation(n, r);

    printf("nCr = %lld\n", nCr);
    printf("r! = %lld\n", rFact);
    printf("nPr = %lld\n", nPr);
    printf("r! * nCr = %lld\n", rFact * nCr);

    // Proving the identity
    if (nPr == rFact * nCr) {
        printf("\n✅ Identity proved: nPr = r! × nCr\n");
    } else {
        printf("\n❌ Identity not proved.\n");
    }

    return 0;
}
