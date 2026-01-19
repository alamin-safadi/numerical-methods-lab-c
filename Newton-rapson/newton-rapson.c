#include <stdio.h>
#include <math.h>

// Function prototypes
double f(double x);      // Function f(x)
double df(double x);     // Derivative f'(x)

int main() {
    double a, b, x0, x1, x_prev;
    double fa, fb, fx, dfx;
    int iteration = 0;
    int matched_count = 0;

    printf("NEWTON-RAPHSON METHOD (YOUR PROCEDURE)\n");
    printf("=======================================\n\n");

    // Step 1: Already have f'(x) defined in df() function

    // Step 2: Find a,b such that f(a)*f(b) < 0
    printf("Step 2: Find interval [a, b] where f(a)*f(b) < 0\n");
    printf("Enter a: ");
    scanf("%lf", &a);
    printf("Enter b: ");
    scanf("%lf", &b);

    fa = f(a);
    fb = f(b);

    if (fa * fb >= 0) {
        printf("Error: f(%.2f)*f(%.2f) = %.4f ≥ 0\n", a, b, fa*fb);
        printf("Function must change sign in the interval.\n");
        return 1;
    }

    printf("f(%.2f) = %.4f, f(%.2f) = %.4f\n", a, fa, b, fb);
    printf("f(a)*f(b) = %.4f < 0 ✓\n\n", fa*fb);

    // Step 3: Assume x0 = a
    x0 = a;
    printf("Step 3: Assume x0 = a = %.4f\n\n", x0);

    printf("Step 4 & 5: Iterations until two successive values match\n");
    printf("=======================================================\n");
    printf("Iter\t  x_n\t\t  f(x_n)\t  f'(x_n)\t  x_n+1\n");
    printf("----------------------------------------------------------------\n");

    do {
        iteration++;

        // Calculate f(x_n) and f'(x_n)
        fx = f(x0);
        dfx = df(x0);

        // Step 4: x_n+1 = x_n - f(x_n)/f'(x_n)
        x1 = x0 - fx / dfx;

        printf("%4d\t%.8f\t%.8f\t%.8f\t%.8f\n",
               iteration, x0, fx, dfx, x1);

        // Step 5: Check if two successive values are equal
        if (iteration > 1 && fabs(x1 - x_prev) < 1e-10) {
            matched_count++;
        } else {
            matched_count = 0;
        }

        // Store current value for next comparison
        x_prev = x1;

        // Update for next iteration
        x0 = x1;

        // Additional check for derivative zero
        if (fabs(dfx) < 1e-15) {
            printf("\nWarning: Derivative is very close to zero!\n");
            break;
        }

    } while (matched_count < 2 && iteration < 100);

    printf("\n----------------------------------------------------------------\n");
    printf("RESULTS:\n");
    printf("Root found: %.10f\n", x1);
    printf("f(root) = %.10f\n", f(x1));
    printf("Iterations: %d\n", iteration);

    // Verify if root is within [a, b]
    if (x1 >= a && x1 <= b) {
        printf("Root lies within interval [%.4f, %.4f] ✓\n", a, b);
    } else {
        printf("Note: Root is outside initial interval [%.4f, %.4f]\n", a, b);
    }

    return 0;
}

// Example function: f(x)
double f(double x) {
    return 3*x-cos(x) - 1;
}

// Derivative: f'(x)
double df(double x) {
    return 3 + sin(x);
}
