#include <stdio.h>

int main() {
    char ch;

    printf("Enter an alphabet: ");
    scanf(" %c", &ch);

    switch (ch) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':

        printf("%c is a Vowel\n", ch);
        break;

        default:
            printf("%c is a Consonant\n", ch);
            break;
    }

    return 0;
}
