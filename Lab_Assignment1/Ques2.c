#include <stdio.h>

int main() {
    int n, i;
    float sum = 0, average;

    // Ask user for the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Declare an array to hold the integers
    int arr[n];

    // Read integers from the user
    printf("Enter %d integers:\n", n);
    for(i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    // Calculate average
    average = sum / n;

    // Print the result
    printf("Average of the entered numbers: %.2f\n", average);

    return 0;
}
