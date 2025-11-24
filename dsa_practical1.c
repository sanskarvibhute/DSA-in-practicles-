/* Experiment No.: 1

Title: Write a C program to calculate the standard deviation of N numbers.
 */

 
#include <stdio.h>
#include <math.h>

int main() {
    int n, i;
    float numbers[100], mean = 0.0, sum = 0.0, standardDeviation = 0.0;

    printf("Enter the number of elements (N): ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);
    for(i = 0; i < n; ++i) {
        scanf("%f", &numbers[i]);
        sum += numbers[i];
    }

    mean = sum / n;

    sum = 0.0;
    for(i = 0; i < n; ++i) {
        sum += pow(numbers[i] - mean, 2);
    }

    standardDeviation = sqrt(sum / n);

    printf("Standard Deviation = %.2f\n", standardDeviation);

    return 0;
}

