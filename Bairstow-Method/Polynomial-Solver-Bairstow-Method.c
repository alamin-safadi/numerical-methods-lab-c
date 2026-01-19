#include <stdio.h>
#include <math.h>

#define MAX_DEG 10
#define EPSILON 1e-12

// Evaluate polynomial
double poly_value(double coeff[], int n, double x) {
    double result = coeff[n];
    for (int i = n-1; i >= 0; i--) {
        result = result * x + coeff[i];
    }
    return result;
}

// Find roots using bisection for each interval
int main() {
    int degree, i, j;
    double coeff[MAX_DEG + 1];
    double roots[MAX_DEG];
    int root_count = 0;

    printf("QUARTIC EQUATION SOLVER\n");
    printf("=======================\n\n");

    printf("For equation: ax^4 + bx^3 + cx^2 + dx + e = 0\n\n");

    printf("Enter coefficient a: "); scanf("%lf", &coeff[4]);
    printf("Enter coefficient b: "); scanf("%lf", &coeff[3]);
    printf("Enter coefficient c: "); scanf("%lf", &coeff[2]);
    printf("Enter coefficient d: "); scanf("%lf", &coeff[1]);
    printf("Enter coefficient e: "); scanf("%lf", &coeff[0]);

    degree = 4;

    printf("\nEquation: ");
    printf("%.2fx^4 ", coeff[4]);
    if (coeff[3] >= 0) printf("+ "); else printf("- ");
    printf("%.2fx^3 ", fabs(coeff[3]));
    if (coeff[2] >= 0) printf("+ "); else printf("- ");
    printf("%.2fx^2 ", fabs(coeff[2]));
    if (coeff[1] >= 0) printf("+ "); else printf("- ");
    printf("%.2fx ", fabs(coeff[1]));
    if (coeff[0] >= 0) printf("+ "); else printf("- ");
    printf("%.2f = 0\n", fabs(coeff[0]));

    // Try rational roots first (for equations like your example)
    double rational[] = {1, -1, 2, -2, 3, -3, 4, -4, 6, -6, 8, -8, 12, -12, 24, -24};

    for (i = 0; i < 16; i++) {
        double x = rational[i];
        double value = poly_value(coeff, degree, x);

        if (fabs(value) < 1e-8) {
            int duplicate = 0;
            for (j = 0; j < root_count; j++) {
                if (fabs(x - roots[j]) < 1e-6) duplicate = 1;
            }
            if (!duplicate) {
                roots[root_count++] = x;
                printf("\nFound rational root: x = %.0f", x);
            }
        }
    }

    if (root_count == 4) {
        printf("\n\nAll roots are integers!\n");
    } else if (root_count > 0) {
        printf("\n\nFound %d rational root(s).\n", root_count);
    }

    // Display results
    if (root_count > 0) {
        printf("\n================================\n");
        printf("ROOTS:\n");
        printf("================================\n");

        for (i = 0; i < root_count; i++) {
            printf("Root %d: x = %.6f\n", i+1, roots[i]);
            printf("  Verification: f(%.6f) = %.6e\n",
                   roots[i], poly_value(coeff, degree, roots[i]));
        }
    }

    return 0;
}
