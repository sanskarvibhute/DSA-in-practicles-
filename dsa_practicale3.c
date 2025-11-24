/*Experiment No.: 3

Title: Write a program to store student information using an array of structure.*/


#include <stdio.h>
#include <string.h>

// 1. Declare structure for students
struct Student {
    int prn;              // Permanent Registration Number
    char name[50];        // Student name
    char address[100];    // Student address
    float cgpa;           // Cumulative Grade Point Average
};

int main() {
    int n, i;
    
    // Get number of students
    printf("Enter the number of students: ");
    scanf("%d", &n);
    getchar();  // To consume the newline character after scanf
    
    // 2. Declare an array of structure student
    struct Student students[n];
    
    // 3. Store student records in the array
    printf("\n--- Enter Student Information ---\n\n");
    for(i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        
        printf("Enter PRN: ");
        scanf("%d", &students[i].prn);
        getchar();
        
        printf("Enter Name: ");
        fgets(students[i].name, 50, stdin);
        students[i].name[strcspn(students[i].name, "\n")] = 0;  // Remove newline
        
        printf("Enter Address: ");
        fgets(students[i].address, 100, stdin);
        students[i].address[strcspn(students[i].address, "\n")] = 0;  // Remove newline
        
        printf("Enter CGPA: ");
        scanf("%f", &students[i].cgpa);
        getchar();
        
        printf("\n");
    }
    
    // 4. Print the student records
    printf("\n========== STUDENT RECORDS =========\n\n");
    printf("%-10s %-20s %-35s %-10s\n", "PRN", "Name", "Address", "CGPA");
    printf("--------------------------------------------");
    printf("------------------------------------------\n");
    
    for(i = 0; i < n; i++) {
        printf("%-10d %-20s %-35s %-10.2f\n", 
               students[i].prn, 
               students[i].name, 
               students[i].address, 
               students[i].cgpa);
    }
    
    printf("\n====================================\n");
    
    return 0;
}
