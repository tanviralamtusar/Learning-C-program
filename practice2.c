#include <stdio.h>

int main() {
    int count, n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    count=1;
    while(count<=n){
        if(count%2==1){
            printf("odd numbers are: %d\n", count);
        } else printf("even numbers: %d\n", count);
        count++;
    }
    return 0;
}
