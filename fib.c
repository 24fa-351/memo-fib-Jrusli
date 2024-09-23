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

    unsigned long long *memo = (unsigned long long *)malloc((n + 1) * sizeof(unsigned long long));

    for (int io = 0; io <= n; io++) {
        memo[io] = -1;
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


unsigned long long recursive(int input, unsigned long long *memo) {
    if (input == 1) {
        return 0;
    }
    if (input == 2) {
        return 1;
    }


    if (memo[input] != -1) {
        return memo[input];
    }

    memo[input] = recursive(input - 1, memo) + recursive(input - 2, memo);
    return memo[input];
}


unsigned long long iterative(int input, unsigned long long *memo) {
    if (input == 1) {
        return 0;
    }
    if (input == 2) {
        return 1;
    }

    unsigned long long num1 = 0;
    unsigned long long num2 = 1;
    for (int ix = 3; ix <= input; ix++) {
        unsigned long long temp = num2;
        num2 = num2 + num1;
        num1 = temp;
    }

    memo[input] = num2;
    return memo[input];
}
