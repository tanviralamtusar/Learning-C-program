#include <stdio.h>

int main(){
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);
    int marks[n];
    int sum = 0;
    printf("Enter the marks of %d students:\n", n);
    for(int i=0; i<n ; i++ ){
        scanf("%d", &marks[i]);
        sum += marks[i];
    }
    
    float average;
    average = (float)sum/n;
    int highest = -1;
    int second_highest = -1;
    
    for(int i=0; i<n; i++){
        if(marks[i]>highest){
            second_highest = highest;
            highest = marks[i];
        } else if (marks[i]> second_highest && marks[i] != highest){
            second_highest = marks[i];
        }
    }
    
    int above=0;
    for(int i=0; i<n; i++){
        if(marks[i]>averege){
            above++;
        }
    }

    printf("Class Average: %.2f\n", average);
    printf("Highest Mark: %d\n", highest);
    if (second_highest == -1) {
        printf("No Second-Highest Mark.\n");
    } else {
        printf("Second-Highest Mark: %d\n", second_highest);
    }
    printf("Number of students above average: %d\n", above);
    printf("Marks below average (in reverse order): ");
    for (int i = n - 1; i >= 0; i--) {
        if (marks[i] < average) {
            printf("%d ", marks[i]);
        }
    }
    printf("\n");

    return 0;

}
