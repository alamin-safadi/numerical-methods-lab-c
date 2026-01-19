#include <stdio.h>
#include <math.h>

#define MAX_POINTS 20

// Function to calculate factorial
int factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

// Function to calculate forward differences
void calculate_forward_differences(double x[], double y[][MAX_POINTS], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            y[i][j] = y[i-1][j+1] - y[i-1][j];
        }
    }
}

// Newton's Forward Interpolation
double newton_forward_interpolation(double x[], double y[][MAX_POINTS],
                                    int n, double x_value) {
    double h = x[1] - x[0];  // Interval size
    double u = (x_value - x[0]) / h;
    double result = y[0][0];
    double term = 1.0;

    for (int i = 1; i < n; i++) {
        term = term * (u - (i - 1)) / i;
        result += term * y[i][0];
    }

    return result;
}

int main() {
    int n, i, j;
    double x[MAX_POINTS];
    double y[MAX_POINTS][MAX_POINTS];
    double x_value, result;

    printf("NEWTON'S FORWARD DIFFERENCE INTERPOLATION\n");
    printf("=========================================\n\n");

    // Input number of data points
    printf("Enter number of data points (max %d): ", MAX_POINTS);
    scanf("%d", &n);

    if (n > MAX_POINTS || n < 2) {
        printf("Invalid number of points!\n");
        return 1;
    }

    // Input data points
    printf("\nEnter data points in ascending order of x:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%lf", &x[i]);
        printf("y[%d] = ", i);
        scanf("%lf", &y[0][i]);
    }

    // Calculate forward differences
    calculate_forward_differences(x, y, n);

    // Display forward difference table
    printf("\nFORWARD DIFFERENCE TABLE:\n");
    printf("==========================\n");
    printf("x\t\ty\t\t");
    for (i = 1; i < n; i++) {
        printf("Δ^%dy\t\t", i);
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        printf("%.4f\t\t", x[i]);
        for (j = 0; j < n - i; j++) {
            printf("%.4f\t\t", y[j][i]);
        }
        printf("\n");
    }

    // Input point for interpolation
    printf("\nEnter the value of x for interpolation: ");
    scanf("%lf", &x_value);

    // Check if x_value is within range
    if (x_value < x[0] || x_value > x[n-1]) {
        printf("Warning: x = %.4f is outside the range [%.4f, %.4f]\n",
               x_value, x[0], x[n-1]);
    }

    // Perform interpolation
    result = newton_forward_interpolation(x, y, n, x_value);

    // Display result
    printf("\n=========================================\n");
    printf("INTERPOLATION RESULT\n");
    printf("=========================================\n");
    printf("For x = %.4f, interpolated y = %.6f\n", x_value, result);

    return 0;
}
