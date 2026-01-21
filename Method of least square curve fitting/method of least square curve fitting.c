#include <stdio.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_DEGREE 10

void gaussian_elimination(double A[][MAX_DEGREE+2], int n, double X[]);

int main() {
    int n, m, i, j, k;
    double x[MAX_POINTS], y[MAX_POINTS];
    double sum_x[2*MAX_DEGREE+1] = {0};
    double sum_xy[MAX_DEGREE+1] = {0};
    double A[MAX_DEGREE+1][MAX_DEGREE+2]; // Augmented matrix
    double coeff[MAX_DEGREE+1];

    printf("LEAST SQUARES POLYNOMIAL CURVE FITTING\n");
    printf("======================================\n\n");

    // Step 1: Input number of data points
    printf("Enter number of data points: ");
    scanf("%d", &n);

    if (n > MAX_POINTS || n < 2) {
        printf("Invalid number of points!\n");
        return 1;
    }

    // Step 2: Input polynomial degree
    printf("Enter degree of polynomial to fit (max %d): ", MAX_DEGREE);
    scanf("%d", &m);

    if (m > MAX_DEGREE || m < 1 || m >= n) {
        printf("Invalid polynomial degree!\n");
        printf("Degree must be: 1 <= degree < number of points\n");
        return 1;
    }

    // Step 3: Input data points
    printf("\nEnter data points (x, y):\n");
    for (i = 0; i < n; i++) {
        printf("Point %d:\n", i+1);
        printf("  x = ");
        scanf("%lf", &x[i]);
        printf("  y = ");
        scanf("%lf", &y[i]);
    }

    // Check for duplicate x values
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            if (fabs(x[i] - x[j]) < 1e-10) {
                printf("\nWarning: Duplicate x value found (x = %.2f)\n", x[i]);
                printf("This may cause problems in curve fitting.\n");
            }
        }
    }

    // Step 4: Calculate sums needed for normal equations
    for (i = 0; i < n; i++) {
        double x_power = 1.0;

        for (j = 0; j <= 2*m; j++) {
            sum_x[j] += x_power;
            if (j <= m) {
                sum_xy[j] += x_power * y[i];
            }
            x_power *= x[i];
        }
    }

    // Display sums for verification
    printf("\nCalculated sums:\n");
    printf("Sum of x^k from k=0 to %d:\n", 2*m);
    for (j = 0; j <= 2*m; j++) {
        printf("  sum_x[%d] = %.4f\n", j, sum_x[j]);
    }
    printf("\nSum of x^k * y from k=0 to %d:\n", m);
    for (j = 0; j <= m; j++) {
        printf("  sum_xy[%d] = %.4f\n", j, sum_xy[j]);
    }

    // Step 5: Set up normal equations
    printf("\nNormal equations matrix:\n");
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= m; j++) {
            A[i][j] = sum_x[i+j];
            printf("%12.4f ", A[i][j]);
        }
        A[i][m+1] = sum_xy[i];
        printf(" | %12.4f\n", A[i][m+1]);
    }

    // Step 6: Solve the system using Gaussian elimination
    gaussian_elimination(A, m+1, coeff);

    // Step 7: Display results
    printf("\n======================================\n");
    printf("LEAST SQUARES POLYNOMIAL FITTING RESULTS\n");
    printf("======================================\n");

    printf("Fitted polynomial of degree %d:\n", m);
    printf("y = ");
    for (i = 0; i <= m; i++) {
        if (i == 0) {
            printf("%.6f", coeff[i]);
        } else if (i == 1) {
            printf(" %+.6f*x", coeff[i]);
        } else {
            printf(" %+.6f*x^%d", coeff[i], i);
        }
    }
    printf("\n\n");

    // Step 8: Display coefficients
    printf("Coefficients:\n");
    for (i = 0; i <= m; i++) {
        printf("a%d = %.6f\n", i, coeff[i]);
    }
    printf("\n");

    // Step 9: Calculate goodness of fit
    double ss_total = 0, ss_residual = 0;
    double mean_y = 0;

    // Calculate mean of y
    for (i = 0; i < n; i++) {
        mean_y += y[i];
    }
    mean_y /= n;

    // Calculate sum of squares
    for (i = 0; i < n; i++) {
        // Calculate predicted y for this point
        double y_pred = coeff[0];
        double x_power = x[i];
        for (j = 1; j <= m; j++) {
            y_pred += coeff[j] * x_power;
            x_power *= x[i];
        }

        ss_total += (y[i] - mean_y) * (y[i] - mean_y);
        ss_residual += (y[i] - y_pred) * (y[i] - y_pred);
    }

    double r_squared = 1.0 - ss_residual / ss_total;
    printf("Goodness of fit:\n");
    printf("R-squared = %.6f\n", r_squared);
    printf("Total sum of squares = %.6f\n", ss_total);
    printf("Residual sum of squares = %.6f\n", ss_residual);

    // Step 10: Display data points with predicted values
    // Using simple ASCII characters instead of box-drawing characters
    printf("\nData points and fitted values:\n");
    printf("----------------------------------------\n");
    printf("    x         y       y_predicted   Error\n");
    printf("----------------------------------------\n");

    double total_error = 0;
    for (i = 0; i < n; i++) {
        double y_pred = coeff[0];
        double x_power = x[i];
        for (j = 1; j <= m; j++) {
            y_pred += coeff[j] * x_power;
            x_power *= x[i];
        }

        double error = y[i] - y_pred;
        total_error += fabs(error);

        printf("%8.4f   %8.4f   %12.4f   %8.4f\n",
               x[i], y[i], y_pred, error);
    }
    printf("----------------------------------------\n");
    printf("Mean absolute error: %.4f\n", total_error / n);

    return 0;
}

// Gaussian elimination to solve linear equations
void gaussian_elimination(double A[][MAX_DEGREE+2], int n, double X[]) {
    int i, j, k;

    // Forward elimination with partial pivoting
    for (i = 0; i < n; i++) {
        // Partial pivoting
        int max_row = i;
        for (j = i+1; j < n; j++) {
            if (fabs(A[j][i]) > fabs(A[max_row][i])) {
                max_row = j;
            }
        }

        // Swap rows if needed
        if (max_row != i) {
            for (k = i; k <= n; k++) {
                double temp = A[i][k];
                A[i][k] = A[max_row][k];
                A[max_row][k] = temp;
            }
        }

        // Eliminate below current row
        for (j = i+1; j < n; j++) {
            double factor = A[j][i] / A[i][i];
            for (k = i; k <= n; k++) {
                A[j][k] -= factor * A[i][k];
            }
        }
    }

    // Back substitution
    for (i = n-1; i >= 0; i--) {
        X[i] = A[i][n];
        for (j = i+1; j < n; j++) {
            X[i] -= A[i][j] * X[j];
        }
        X[i] /= A[i][i];
    }
}
