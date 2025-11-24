/*  Experiment No. 3
Title: Write a program to implement Static List / ArrayList using array.
Basic Operations of the list:
    1.Insertion
    2.Deletion
    3.Search
    4.Traverse.
*/
//--------------------------------------------CODE FILES--------------------------------//

#include <stdio.h>
#define MAX 100 //DEFINING MAX = 100

int arr[MAX];
int n = 0;   // current size

//--------------------------------------------FUNCTIONS--------------------------------//
    
void traverse() {
    int i;
    if (n == 0) {
        printf("List is empty.\n");
        return;
    }
    printf("Elements: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);  // simple array traversal
    }
    printf("\n");
}

// --------------------------------------------INSERT FUNCTIONS--------------------------------//

void insertAtBegin(int x) {
    int i;
    if (n == MAX) {
        printf("List is full.\n");
        return;
    }
    for (i = n; i > 0; i--) {   // shift right
        arr[i] = arr[i - 1];
    }
    arr[0] = x;
    n++;
}

void insertAtEnd(int x) {
    if (n == MAX) {
        printf("List is full.\n");
        return;
    }
    arr[n] = x;
    n++;
}

void insertAtPos(int pos, int x) {
    int i;
    if (n == MAX) {
        printf("List is full.\n");
        return;
    }
    // positions are 1..n+1
    if (pos < 1 || pos > n + 1) {
        printf("Invalid position.\n");
        return;
    }
    for (i = n; i >= pos; i--) {   // shift right from pos-1
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = x;
    n++;
}

// --------------------------------------------DELETE FUNCTIONS--------------------------------//

void deleteAtBegin() {
    int i;
    if (n == 0) {
        printf("List is empty.\n");
        return;
    }
    for (i = 0; i < n - 1; i++) {  // shift left
        arr[i] = arr[i + 1];
    }
    n--;
}

void deleteAtEnd() {
    if (n == 0) {
        printf("List is empty.\n");
        return;
    }
    n--;
}

void deleteAtPos(int pos) {
    int i;
    if (n == 0) {
        printf("List is empty.\n");
        return;
    }
    if (pos < 1 || pos > n) {
        printf("Invalid position.\n");
        return;
    }
    for (i = pos - 1; i < n - 1; i++) {  // shift left from pos
        arr[i] = arr[i + 1];
    }
    n--;
}

// --------------------------------------------SEARCH FUNCTION--------------------------------//

int search(int key) {
    int i;
    for (i = 0; i < n; i++) {          // linear search
        if (arr[i] == key)
            return i;                  // index
    }
    return -1;
}

int main() {
    int choice, x, pos, index, ch;
    while (1) {
        printf("\n---- Static List (ArrayList) ----\n");
        printf("1. Insert at Begin\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specific Position\n");
        printf("4. Delete at Begin\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Specific Position\n");
        printf("7. Search\n");
        printf("8. Traverse\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            while ((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }

        switch (choice) {
        case 1:
            printf("Enter element: ");
            if (scanf("%d", &x) != 1) {
                printf("Invalid input.\n");
                while ((ch = getchar()) != '\n' && ch != EOF);
                break;
            }
            insertAtBegin(x);
            break;
        case 2:
            printf("Enter element: ");
            if (scanf("%d", &x) != 1) {
                printf("Invalid input.\n");
                while ((ch = getchar()) != '\n' && ch != EOF);
                break;
            }
            insertAtEnd(x);
            break;
        case 3:
            printf("Enter position (1-based): ");
            if (scanf("%d", &pos) != 1) {
                printf("Invalid input.\n");
                while ((ch = getchar()) != '\n' && ch != EOF);
                break;
            }
            printf("Enter element: ");
            if (scanf("%d", &x) != 1) {
                printf("Invalid input.\n");
                while ((ch = getchar()) != '\n' && ch != EOF);
                break;
            }
            insertAtPos(pos, x);
            break;
        case 4:
            deleteAtBegin();
            break;
        case 5:
            deleteAtEnd();
            break;
        case 6:
            printf("Enter position (1-based): ");
            if (scanf("%d", &pos) != 1) {
                printf("Invalid input.\n");
                while ((ch = getchar()) != '\n' && ch != EOF);
                break;
            }
            deleteAtPos(pos);
            break;
        case 7:
            printf("Enter element to search: ");
            if (scanf("%d", &x) != 1) {
                printf("Invalid input.\n");
                while ((ch = getchar()) != '\n' && ch != EOF);
                break;
            }
            index = search(x);
            if (index == -1)
                printf("Element not found.\n");
            else
                printf("Element found at position %d.\n", index + 1);
            break;
        case 8:
            traverse();
            break;
        case 9:
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }
}
