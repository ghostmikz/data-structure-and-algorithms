#include <stdio.h>

int factorialIterative(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
        printf("Step %d: %d\n", i, result);
    }
    return result;
}

int factorialRecursive(int n) {
    if (n == 0) return 1;
    return n * factorialRecursive(n - 1);
}

int fibonacciIterative(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int a = 0, b = 1, c;
    printf("Fib 0: %d\n", a);
    printf("Fib 1: %d\n", b);

    for (int i = 2; i <= n; i++) {
        c = a + b;
        printf("Fib %d: %d\n", i, c);
        a = b;
        b = c;
    }
    return b;
}

int fibonacciRecursive(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int powerIterative(int n, int k) {
    int result = 1;
    for (int i = 1; i <= k; i++) {
        result *= n;
        printf("Step %d: %d\n", i, result);
    }
    return result;
}

int powerRecursive(int n, int k) {
    if (k == 0) return 1;
    return n * powerRecursive(n, k - 1);
}

int main() {
    int choice, n, k;

    while (1) {
        printf("\n1. Factorial (Iterative)");
        printf("\n2. Factorial (Recursive)");
        printf("\n3. Fibonacci nth (Iterative)");
        printf("\n4. Fibonacci nth (Recursive)");
        printf("\n5. Power n^k (Iterative)");
        printf("\n6. Power n^k (Recursive)");
        printf("\n7. Exit");
        printf("\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter n: ");
                scanf("%d", &n);
                printf("Factorial %d = %d\n", n, factorialIterative(n));
                break;
            case 2:
                printf("Enter n: ");
                scanf("%d", &n);
                printf("Factorial %d = %d\n", n, factorialRecursive(n));
                break;
            case 3:
                printf("Enter n: ");
                scanf("%d", &n);
                printf("Fibonacci %d = %d\n", n, fibonacciIterative(n));
                break;
            case 4:
                printf("Enter n: ");
                scanf("%d", &n);
                printf("Fibonacci %d = %d\n", n, fibonacciRecursive(n));
                break;
            case 5:
                printf("Enter n and k: ");
                scanf("%d %d", &n, &k);
                printf("%d^%d = %d\n", n, k, powerIterative(n, k));
                break;
            case 6:
                printf("Enter n and k: ");
                scanf("%d %d", &n, &k);
                printf("%d^%d = %d\n", n, k, powerRecursive(n, k));
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
