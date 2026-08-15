#include<stdio.h>

int main(){
    int s=0,n,c=1;
    do{
        printf("Enter a number:");
        scanf("%d", &n);
        s=s+n;
        c++;
    }while(c<=10);
    printf("sum: %d", s);
    return 0;
}
