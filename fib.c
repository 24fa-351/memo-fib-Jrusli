#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes with memoization array passed as a parameter
unsigned long long recursive(int n, unsigned long long *memo);
unsigned long long iterative(int n, unsigned long long *memo);

int main(int argc, char *argv[]) {

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_num> <method>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);


    if (n <= 0) {
        fprintf(stderr, "Error: Input number must be a positive integer.\n");
        return 1;
    }

    unsigned long long *memo = (unsigned long long *)malloc((n + 1) * sizeof(unsigned long long));

    for (int i = 0; i <= n; i++) {
        memo[i] = -1;
    }

    unsigned long long result;
   
    if (strcmp(argv[2], "r") == 0) {
        result = recursive(n, memo);
    } else if (strcmp(argv[2], "i") == 0) {
        result = iterative(n, memo);
    }

 
    printf("%llu\n", result);

  

    return 0;
}


unsigned long long recursive(int n, unsigned long long *memo) {
    if (n == 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }


    if (memo[n] != -1) {
        return memo[n];
    }

    memo[n] = recursive(n - 1, memo) + recursive(n - 2, memo);
    return memo[n];
}


unsigned long long iterative(int n, unsigned long long *memo) {
    if (n == 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }

    unsigned long long a = 0;
    unsigned long long b = 1;
    for (int i = 3; i <= n; i++) {
        unsigned long long temp = b;
        b = b + a;
        a = temp;
    }

    memo[n] = b;
    return memo[n];
}
