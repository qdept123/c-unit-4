#include <stdio.h>

// Function to generate next random number using LCM
unsigned long long lcg(unsigned long long *seed, unsigned long long a, unsigned long long c, unsigned long long m) {
    *seed = (a * (*seed) + c) % m;
    return *seed;
}

int main() {
    // Parameters for LCG (these work well and are commonly used)
    unsigned long long a = 1664525;         // Multiplier
    unsigned long long c = 1013904223;      // Increment
    unsigned long long m = 4294967296ULL;   // Modulus (2^32)
    unsigned long long seed;

    int n;

    printf("Enter seed value (e.g., 123): ");
    scanf("%llu", &seed);

    printf("Enter how many random numbers to generate: ");
    scanf("%d", &n);

    printf("Generated random numbers:\n");
    for (int i = 0; i < n; i++) {
        unsigned long long randNum = lcg(&seed, a, c, m);
        printf("%llu\n", randNum);
    }

    return 0;
}
