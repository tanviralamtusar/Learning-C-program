#include <stdio.h>

int main() {
    int F;
    printf("Enter a number: ");
    scanf("%d", &F);

    if (F % 5 == 0 && F % 11 == 0) {
        printf("This number %d is divisible by 5 and 11", F);
    } else {
        printf("This number %d is not divisible by 5 and 11", F);
    }

    return 0;
}
