#include <stdio.h>

int sumOfDigits(int n) {
    if (n == 0) {
        return 0;
    }
    return (n % 10) + sumOfDigits(n / 10);
}

int reverseNumber(int n, int rev) {
    if (n == 0) {
        return rev;
    }
    return reverseNumber(n / 10, (rev * 10) + (n % 10));
}

int countDigits(int n) {
    if (n == 0) {
        return 0;
    }
    return 1 + countDigits(n / 10);
}

int isPalindrome(int n) {
    return (n == reverseNumber(n, 0));
}

int main() {
    int num;

    printf("Enter a positive integer: ");
    scanf("%d", &num);
    printf("Sum digits: %d\n", sumOfDigits(num));

    printf("Reversed number: %d\n", reverseNumber(num, 0));

    printf("Total number of digits: %d\n", countDigits(num));

    if (isPalindrome(num)) {
        printf("%d is a Palindrome.\n", num);
    } else {
        printf("%d is NOT a Palindrome.\n", num);
    }

    return 0;
}