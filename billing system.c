#include <stdio.h>
#include <string.h>

// 1. Structure to store each grocery item
struct Item {
    char name[50];
    int quantity;
    float price;
    float subtotal;
};

// Function 1: Take input for each item
void inputItems(struct Item items[], int count) {
    for (int i = 0; i < count; i++) {
        printf("\n--- Item %d ---\n", i + 1);
        printf("Item Name (single word, e.g., Rice): ");
        scanf("%s", items[i].name);

        printf("Quantity: ");
        scanf("%d", &items[i].quantity);

        printf("Unit Price (BDT): ");
        scanf("%f", &items[i].price);

        items[i].subtotal = items[i].quantity * items[i].price;
    }
}

// Function 2: Calculate bill, 5% discount, and split amount using pointers
void calculateBill(struct Item items[], int count, float *subtotal, float *discount, float *grandTotal, int people, float *perPerson) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum = sum + items[i].subtotal;
    }

    *subtotal = sum;

    // Apply 5% discount if subtotal is 1000 BDT or more
    if (*subtotal >= 1000.0) {
        *discount = (*subtotal) * 0.05;
    } else {
        *discount = 0.0;
    }

    *grandTotal = (*subtotal) - (*discount);
    *perPerson = (*grandTotal) / people;
}

// Function 3: Print receipt on the screen
void displayReceipt(char customerName[], struct Item items[], int count, float subtotal, float discount, float grandTotal, int people, float perPerson) {
    printf("\n============================================\n");
    printf("              GROCERY RECEIPT               \n");
    printf("============================================\n");
    printf("Customer: %s\n", customerName);
    printf("--------------------------------------------\n");
    printf("Item\t\tQty\tPrice\tSubtotal\n");
    printf("--------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%s\t\t%d\t%.2f\t%.2f\n", items[i].name, items[i].quantity, items[i].price, items[i].subtotal);
    }

    printf("--------------------------------------------\n");
    printf("Subtotal        : %.2f BDT\n", subtotal);
    printf("Discount (5%%)   : -%.2f BDT\n", discount);
    printf("Grand Total     : %.2f BDT\n", grandTotal);
    printf("Split (%d people): %.2f BDT each\n", people, perPerson);
    printf("============================================\n");
}

// Function 4: Save receipt into receipt.txt file
void saveReceiptToFile(char customerName[], struct Item items[], int count, float subtotal, float discount, float grandTotal, int people, float perPerson) {
    FILE *fp = fopen("receipt.txt", "w");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(fp, "============================================\n");
    fprintf(fp, "              GROCERY RECEIPT               \n");
    fprintf(fp, "============================================\n");
    fprintf(fp, "Customer: %s\n", customerName);
    fprintf(fp, "--------------------------------------------\n");
    fprintf(fp, "Item\t\tQty\tPrice\tSubtotal\n");
    fprintf(fp, "--------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s\t\t%d\t%.2f\t%.2f\n", items[i].name, items[i].quantity, items[i].price, items[i].subtotal);
    }

    fprintf(fp, "--------------------------------------------\n");
    fprintf(fp, "Subtotal        : %.2f BDT\n", subtotal);
    fprintf(fp, "Discount (5%%)   : -%.2f BDT\n", discount);
    fprintf(fp, "Grand Total     : %.2f BDT\n", grandTotal);
    fprintf(fp, "Split (%d people): %.2f BDT each\n", people, perPerson);
    fprintf(fp, "============================================\n");

    fclose(fp);
    printf("\nReceipt saved successfully to receipt.txt!\n");
}

int main() {
    struct Item items[50]; // Fixed array of 50 items (simple & safe)
    char customerName[50];
    int itemCount, peopleCount;
    float subtotal = 0, discount = 0, grandTotal = 0, perPerson = 0;

    printf("=== SMART GROCERY & SPLIT-BILL GENERATOR ===\n");

    printf("Enter Customer Name (one word): ");
    scanf("%s", customerName);

    printf("How many items? ");
    scanf("%d", &itemCount);

    inputItems(items, itemCount);

    printf("\nSplit bill among how many people? ");
    scanf("%d", &peopleCount);

    if (peopleCount <= 0) {
        peopleCount = 1;
    }

    calculateBill(items, itemCount, &subtotal, &discount, &grandTotal, peopleCount, &perPerson);
    displayReceipt(customerName, items, itemCount, subtotal, discount, grandTotal, peopleCount, perPerson);
    saveReceiptToFile(customerName, items, itemCount, subtotal, discount, grandTotal, peopleCount, perPerson);

    return 0;
}
