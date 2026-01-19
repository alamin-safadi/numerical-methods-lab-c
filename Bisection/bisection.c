#include <stdio.h>
#include <math.h>

// Function prototype
double f(double x);

int main() {
    double a, b, c, fa, fb, fc;
    double prev_c = 0.0;  // To store previous root value
    int iteration = 0;
    int matched_count = 0;

    // Step 1: Choose two real numbers a & b such that f(a)*f(b) < 0
    printf("Enter the interval [a, b] where f(a)*f(b) < 0:\n");
    printf("Enter a: ");
    scanf("%lf", &a);
    printf("Enter b: ");
    scanf("%lf", &b);

    fa = f(a);
    fb = f(b);

    // Check if f(a)*f(b) < 0
    if (fa * fb >= 0) {
        printf("Error: f(a)*f(b) must be less than 0.\n");
        printf("f(%.4lf) = %.6lf\n", a, fa);
        printf("f(%.4lf) = %.6lf\n", b, fb);
        return 1;
    }

    printf("\nStarting Bisection Method...\n");
    printf("Iteration\t  a\t\t  b\t\t  c\t\t  f(c)\n");
    printf("----------------------------------------------------------------\n");

    // Main bisection loop
    do {
        iteration++;

        // Step 2: Define root c = (a + b) / 2
        c = (a + b) / 2.0;
        fc = f(c);

        printf("%4d\t\t%.6lf\t%.6lf\t%.6lf\t%.6lf\n", iteration, a, b, c, fc);

        // Check if current root matches previous root
        if (iteration > 1 && fabs(c - prev_c) < 1e-10) {
            matched_count++;
        } else {
            matched_count = 0;
        }

        // Step 4: Check condition and update interval
        if (fa * fc <= 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }

        prev_c = c;  // Store current root for next comparison

    } while (matched_count < 2);  // Continue until root matches twice

    printf("\n----------------------------------------------------------------\n");
    printf("Root found: %.10lf\n", c);
    printf("Function value at root: %.10lf\n", fc);
    printf("Number of iterations: %d\n", iteration);

    return 0;
}

// Define your function here
// Example: f(x) = x^3 - 2x - 5
double f(double x) {
    return 3*x-cos(x)-1;
    // You can change this to any function you want to solve
}
