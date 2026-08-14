#include <stdio.h>

int main() {
    float x, y, sum;

    printf("Enter first number: ");
    scanf("%f", &x);

    printf("Enter second number: ");
    scanf("%f", &y);

    sum = x + y;

    printf("Sum = %.2f\n", sum);

    return 0;
}
