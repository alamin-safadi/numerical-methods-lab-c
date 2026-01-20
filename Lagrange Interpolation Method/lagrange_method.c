#include <stdio.h>
#include <stdlib.h>

// Lagrange Interpolation Function
double lagrangeInterpolation(double x[], double y[], int n, double xp) {
    double result = 0.0;

    for (int i = 0; i < n; i++) {
        double term = y[i];

        for (int j = 0; j < n; j++) {
            if (j != i) {
                term = term * (xp - x[j]) / (x[i] - x[j]);
            }
        }

        result += term;
    }

    return result;
}

int main() {
    int n;  // Number of data points
    double xp;  // Point to interpolate

    printf("=== Lagrange Interpolation Program ===\n\n");

    // Input: Number of data points
    printf("Enter number of data points: ");
    scanf("%d", &n);

    // Dynamic memory allocation
    double *x = (double*)malloc(n * sizeof(double));
    double *y = (double*)malloc(n * sizeof(double));

    if (x == NULL || y == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input: Data points
    printf("\nEnter data points (x y):\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d], y[%d]: ", i, i);
        scanf("%lf %lf", &x[i], &y[i]);
    }

    // Input: Point to interpolate
    printf("\nEnter the point to interpolate (x): ");
    scanf("%lf", &xp);

    // Calculate interpolation
    double yp = lagrangeInterpolation(x, y, n, xp);

    // Display results
    printf("\n=== RESULTS ===\n");
    printf("Data Points:\n");
    for (int i = 0; i < n; i++) {
        printf("(%.2f, %.2f)\n", x[i], y[i]);
    }
    printf("\nInterpolated value at x = %.2f\n", xp);
    printf("y(%.2f) = %.4f\n", xp, yp);

    // Free allocated memory
    free(x);
    free(y);

    return 0;
}
