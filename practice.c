#include <stdio.h>

int main() {
    int count, n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    count=1;
    while(count<=n){
        printf("%d", count);
        count++;
    }
    return 0;
}
