#include<stdio.h>

int main(){
int n,num,even,odd;
even=0;
odd=0;
printf("enter a number:");
scanf("%d", &n);
for(int i=0; i<n; i++){
    printf("enter a value: ");
    scanf("%d", &num);
    if(num%2==0){
        printf("%d is even", num);
        even++;
    }
    else{
        printf("%d is odd", num);
        odd++;
    }
}
printf("even: %d\n", even);
printf("odd: %d\n", odd);
return 0;
}
