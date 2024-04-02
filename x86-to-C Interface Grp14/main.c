#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <immintrin.h>

extern void stencil_kernel_asm(double* X, double* Y, int n);

void stencil_kernel_c(double* X, double* Y, int n);

void generate_random_vector(double* X, int n) {
    for (int i = 0; i < n; ++i) {
        X[i] = (double)rand() / RAND_MAX;
    }
}


void display_results(double* Y, int n) {
    printf("Results:\n");
    for (int i = 0; i < 10; ++i) {
        printf("%.2f ", Y[i]);
    }
    printf("\n");
}

int main() {
    const int n_values[] = { 20, 24, 30 }; // Sizes of n: 2^20, 2^24, 2^30
    const int num_tests = 30;

    srand(time(NULL));

    for (int k = 0; k < sizeof(n_values) / sizeof(int); ++k) {
        int n = 1 << n_values[k];
        double* X = (double*)malloc(n * sizeof(double));
        double* Y_c = (double*)malloc(n * sizeof(double));
        double* Y_asm = (double*)malloc(n * sizeof(double));

        generate_random_vector(X, n);

        // Timing C version
        clock_t start_c = clock();
        for (int i = 0; i < num_tests; ++i) {
            stencil_kernel_c(X, Y_c, n);
        }
        clock_t end_c = clock();
        double elapsed_c = (double)(end_c - start_c) / CLOCKS_PER_SEC / num_tests;

        // Timing assembly version
        clock_t start_asm = clock();
        for (int i = 0; i < num_tests; ++i) {
            stencil_kernel_asm(X, Y_asm, n); //adjust
        }
        clock_t end_asm = clock();
        double elapsed_asm = (double)(end_asm - start_asm) / CLOCKS_PER_SEC / num_tests;

        printf("Vector size: %d\n", n);
        printf("C Version: Average time taken = %f seconds\n", elapsed_c);
        printf("ASM Version: Average time taken = %f seconds\n", elapsed_asm);

        // Displaying results for the first ten elements
        printf("C Version Results:\n");
        display_results(Y_c, n);
        printf("ASM Version Results:\n");
        display_results(Y_asm, n);

        free(X);
        free(Y_c);
        free(Y_asm);
    }

    return 0;
}

void stencil_kernel_c(double* X, double* Y, int n) {
    int i;
    for (i = 3; i < n - 3; i++) {
        Y[i - 3] = X[i - 3] + X[i - 2] + X[i - 1] + X[i] + X[i + 1] + X[i + 2] + X[i + 3];
    }
}
