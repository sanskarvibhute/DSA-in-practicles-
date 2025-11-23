/* Experiment No.: 2

Title: Write a C program to implement Bubble and insertion Sort.
 */

#include <stdio.h>

// Bubble Sort Function
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    printf("\n--- Bubble Sort ---\n");
    
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                // Swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    printf("Sorted array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Insertion Sort Function
void insertionSort(int arr[], int n) {
    int i, j, key, temp;
    printf("\n--- Insertion Sort ---\n");
    
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    
    printf("Sorted array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to display array
void displayArray(int arr[], int n) {
    printf("Original array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr1[100], arr2[100];
    
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
        arr2[i] = arr1[i];  // Copy for second array
    }
    
    displayArray(arr1, n);
    
    // Bubble Sort
    bubbleSort(arr1, n);
    
    // Reset array
    printf("\nResetting array for Insertion Sort...\n");
    for(i = 0; i < n; i++) {
        arr1[i] = arr2[i];
    }
    
    // Insertion Sort
    insertionSort(arr1, n);
    
    return 0;
}
