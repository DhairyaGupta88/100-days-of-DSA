//: Given integers a and b, compute a^b using recursion without using pow() function.
#include <stdio.h>

int power(int a, int b) {
    // Base case
    if (b == 0)
        return 1;

    // Recursive case
    return a * power(a, b - 1);
}

int main() {
    int a, b;

    printf("Enter base (a): ");
    scanf("%d", &a);

    printf("Enter exponent (b): ");
    scanf("%d", &b);

    printf("%d^%d = %d", a, b, power(a, b));

    return 0;
}
