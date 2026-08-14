#include <stdio.h>

int main() {
    int limit, count;
    long long currentTerm = 0, totalSum = 0;
    printf("Enter number of terms: ");
    scanf("%d", &limit);
    for (count = 1; count <= limit; count++) {
        currentTerm = currentTerm * 10 + 1;
        totalSum = totalSum + currentTerm;
    }
    printf("Sum of the series up to %d terms = %lld", limit, totalSum);
    return 0;
}
