#include <stdio.h>

int main() {
    int A, B, C;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &A, &B, &C);

    if (A > B && A > C) {
        printf("Maximum number is %d", A);
    } else if (B > A && B > C) {
        printf("Maximum number is %d", B);
    } else {
        printf("Maximum number is %d", C);
    }

    return 0;
}
