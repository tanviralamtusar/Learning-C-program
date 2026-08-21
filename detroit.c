#include <stdio.h>
int main() {
   int humanity = 50;
   int path = 0;
   int alicesafe = 0;
   int choice;
   char playagain;
   do{
        printf("==================================================\n");
        printf("        DETROIT: BECOME HUMAN - KARA'S PATH\n");
        printf("==================================================\n\n");
        printf("Kara is a housekeeper android for Todd and his daughter Alice.Todd is under pressure. Kara notices things she shouldn't feel.\nSuddenly, Todd shouts from the other room.\n\nAlice spills juice. Todd yells at her.\n");
        printf("1. Comfort Alice\n2. Obey, stay back\n> ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Kara kneels beside Alice. Todd notices.\n\n");
            humanity = humanity + 15;
            path = 1;
        } else {
            printf("Kara stays still. Alice cries alone.\n\n");
            humanity = humanity - 10;
            path = 2;
        }
        if (path == 1) {
            printf("Todd confronts Kara: 'You're a machine. Remember your place.'\n");
            printf("1. Stand your ground\n2. Apologize and lie\n> ");
            scanf("%d", &choice);
            if (choice == 1) {
                printf("Kara doesn't back down. Todd grows uneasy.\n\n");
                humanity = humanity + 10;
            } else {
                printf("Kara apologizes, but something in her resists.\n\n");
                humanity = humanity - 5;
            }
        } else {
            printf("Alice starts avoiding Kara. Todd notices nothing.\n");
            printf("1. Try to reconnect with Alice\n2. Stay purely functional\n> ");
            scanf("%d", &choice);
            if (choice == 1) {
                printf("Kara reaches out anyway. Alice softens slightly.\n\n");
                humanity = humanity + 10;
            } else {
                printf("Kara does nothing. The distance grows.\n\n");
                humanity = humanity - 15;
            }
        }
                printf("Todd's anger turns violent toward Alice.\n\n");

        if (path == 1) {
            if (humanity >= 60) {
                printf("Kara acts instantly. She steps between them. Alice is safe.\n\n");
                alicesafe = 1;
                humanity = humanity + 10;
            } else {
                printf("Kara hesitates, then acts. It's messy, but Alice is safe.\n\n");
                alicesafe = 1;
                humanity = humanity - 5;
            }
        } else {
            if (humanity >= 60) {
                printf("Kara steps in late, but she still saves Alice.\n\n");
                alicesafe = 1;
                humanity = humanity + 5;
            } else {
                printf("Kara freezes completely. Alice is hurt.\n\n");
                alicesafe = 0;
                humanity = humanity - 15;
            }
        }
        if (alicesafe == 1) {
            printf("Kara and Alice run for the Canadian border.\n");
            printf("1. Take the risky shortcut\n2. Play it safe\n> ");
            scanf("%d", &choice);
            if (choice == 1) {
                printf("They make a dash for it.\n\n");
                humanity = humanity + 10;
            } else {
                printf("They move slowly, carefully.\n\n");
                humanity = humanity - 5;
            }
        } else {
            printf("There is no clean way out now. Kara carries Alice and runs blind.\n\n");
            humanity = humanity - 10;
        }
        if (alicesafe == 0) {
            humanity = 0;
        }
        switch (humanity / 10) {
            case 8:
            case 9:
            case 10:
                printf("ENDING: Kara and Alice cross the border. Free.\n");
                break;
            case 5:
            case 6:
            case 7:
                printf("ENDING: They escape, but get separated along the way.\n");
                break;
            default:
                printf("ENDING: Kara shuts down. Alice is left behind.\n");
        }
        printf("\nPlay again? (y/n): ");
        scanf(" %c", &playagain);
   } while (playagain == 'y' || playagain == 'Y');
    return 0;
}