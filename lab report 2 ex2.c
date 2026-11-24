#include <stdio.h>

int isPrime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int isPalindrome(int n) {
    int original = n;
    int reversed = 0;

    while (n > 0) {
        int digit = n % 10;
        reversed = (reversed * 10) + digit;
        n= n/10;
    }

    return (reversed == original);
}

int sumEvenDigits(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        if (digit % 2 == 0) {
            sum = sum +digit;
        }
        n= n/10;
    }
    return sum;
}

int sumOddDigits(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        if (digit % 2 != 0) {
            sum =sum + digit;
        }
        n= n/10;
    }
    return sum;
}

int isArmstrong(int n) {
    int original = n;
    int temp = n;
    int digits = 0;
    int sum = 0;

    while (temp > 0) {
        digits++;
        temp = temp /10;
    }

    temp = n;
    while (temp > 0) {
        int digit = temp % 10;
        int power = 1;
        for (int i = 0; i < digits; i++) {
            power = power *digit;
        }
        sum = sum +power;
        temp = temp /10;
    }

    return (sum == original);
}

int main() {
    int num, evenSum = 0, oddSum = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (isPrime(num)) {
        printf("%d is a Prime number.\n", num);
    } else {
        printf("%d is NOT a Prime number.\n", num);
    }

    if (isPalindrome(num)) {
        printf("%d is a Palindrome.\n", num);
    } else {
        printf("%d is NOT a Palindrome.\n", num);
    }

    evenSum = sumEvenDigits(num);
    oddSum = sumOddDigits(num);
    printf("Even digits sum = %d, Odd digits sum = %d\n", evenSum, oddSum);

    if (isArmstrong(num)) {
        printf("%d is an Armstrong number.\n", num);
    } else {
        printf("%d is NOT an Armstrong number.\n", num);
    }

    return 0;
}