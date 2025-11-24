/*
Experiment No. 4
Title: Write a C program to create a product list the shopping mall.
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define FILE_NAME "product_list.txt"

// Define the Product structure
typedef struct {
    int id;
    char name[50];
    float price;
} Product;

// Global Static List
Product list[MAX];
int count = 0; // Current number of products

// ------------------ Function Prototypes-------------------//

void loadFromFile();
void saveToFile();
void insertProduct();
void deleteProduct();
void searchProduct();
void displayProducts();

int main() {
    int choice;

    // Load existing data from file at startup
    loadFromFile();

    while (1) {
        printf("\n=== Shopping Mall Product List ===\n");
        printf("1. Add Product\n");
        printf("2. Delete Product (by ID)\n");
        printf("3. Search Product (by ID)\n");
        printf("4. Display All Products\n");
        printf("5. Save & Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertProduct();
                break;
            case 2:
                deleteProduct();
                break;
            case 3:
                searchProduct();
                break;
            case 4:
                displayProducts();
                break;
            case 5:
                saveToFile();
                printf("Data saved. Exiting program.\n");
                exit(0);  //give same effect as return 0
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// ---------------------------Function to insert a product at the end of the list-----------------------------//


void insertProduct() {
    if (count >= MAX) {
        printf("List is full! Cannot add more products.\n");
        return;
    }

    Product p;
    printf("Enter Product ID: ");
    scanf("%d", &p.id);
    
    // Check for duplicate ID
    for (int i = 0; i < count; i++) {
        if (list[i].id == p.id) {
            printf("Error: Product ID %d already exists.\n", p.id);
            return;
        }
    }

    printf("Enter Product Name: ");
    scanf("%s", p.name); // Reads single word (use fgets for multi-word)
    printf("Enter Product Price: ");
    scanf("%f", &p.price);

    list[count] = p;
    count++;
    printf("Product added successfully!\n");
}

// Function to delete a product by ID
void deleteProduct() {
    int id, i, found = 0;
    if (count == 0) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter Product ID to delete: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (list[i].id == id) {
            found = 1;
            // Shift elements to the left to fill the gap
            for (int j = i; j < count - 1; j++) {
                list[j] = list[j + 1];
            }
            count--;
            printf("Product with ID %d deleted.\n", id);
            break;
        }
    }

    if (!found) {
        printf("Product with ID %d not found.\n", id);
    }
}

// Function to search for a product by ID
void searchProduct() {
    int id, i, found = 0;
    if (count == 0) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter Product ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (list[i].id == id) {
            printf("\nProduct Found:\n");
            printf("ID: %d | Name: %s | Price: %.2f\n", list[i].id, list[i].name, list[i].price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Product not found.\n");
    }
}

// Function to traverse and display all products
void displayProducts() {
    if (count == 0) {
        printf("List is empty.\n");
        return;
    }

    printf("\n%-10s %-20s %-10s\n", "ID", "Name", "Price");
    printf("------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %-10.2f\n", list[i].id, list[i].name, list[i].price);
    }
}

// Function to save data to file (Text Mode)
void saveToFile() {
    FILE *fp = fopen(FILE_NAME, "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    // Write count first (optional, but helps reading)
    // Then write each product
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d %s %.2f\n", list[i].id, list[i].name, list[i].price);
    }

    fclose(fp);
}

// Function to load data from file (Text Mode)
void loadFromFile() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("No saved data found. Starting with empty list.\n");
        return;
    }

    count = 0;
    // Read until End Of File (EOF)
    while (fscanf(fp, "%d %s %f", &list[count].id, list[count].name, &list[count].price) != EOF) {
        count++;
        if (count >= MAX) break; // Stop if array is full
    }

    fclose(fp);
    printf("Loaded %d products from file.\n", count);
}

