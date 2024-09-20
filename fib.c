#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes with memoization array passed as a parameter
unsigned long long recursive(int n, unsigned long long *memo);
unsigned long long iterative(int n, unsigned long long *memo);

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is passed
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_num> <method> <file_name>\n", argv[0]);
        return 1;
    }

    int input_num = atoi(argv[1]);

    FILE *file = fopen(argv[3], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", argv[3]);
        return 1;
    }

    int file_num;
    if (fscanf(file, "%d", &file_num) != 1) {
        fclose(file);
        return 1;
    }
    fclose(file);

    int n = input_num + file_num;

   
    unsigned long long *memo = (unsigned long long *)malloc((n + 1) * sizeof(unsigned long long));

   
    for (int i = 0; i <= n; i++) {
        memo[i] = -1;
    }

    unsigned long long result;
    if (strcmp(argv[2], "r") == 0) {
        result = recursive(n, memo);
    } else if (strcmp(argv[2], "i") == 0) {
        result = iterative(n, memo);
    } else {
        fprintf(stderr, "Error: Invalid method. Use 'r' for recursive or 'i' for iterative.\n");
        free(memo);
        return 1;
    }

    // Output the Fibonacci number
    printf("%llu\n", result);

    // Free the allocated memory
    free(memo);

    return 0;
}

// Recursive Fibonacci with memoization
unsigned long long recursive(int n, unsigned long long *memo) {
    if (n == 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }

    // Return memoized result if available
    if (memo[n] != -1) {
        return memo[n];
    }

    // Compute and memoize the result
    memo[n] = recursive(n - 1, memo) + recursive(n - 2, memo);
    return memo[n];
}

// Iterative Fibonacci with memoization
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
