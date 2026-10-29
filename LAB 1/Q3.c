//  Bubble Sort

#include <stdio.h>

int main() {
    int n, temp, iterations = 0, comparisons = 0;

    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\n--- Bubble Sort ---\n");
    for (int i = 0; i < n - 1; i++) {
        printf("\nPass %d:\n", i + 1);
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            printf("Comparing arr[%d]=%d and arr[%d]=%d\n",
                   j, arr[j], j + 1, arr[j + 1]);
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                printf("Swapped -> ");
                for (int k = 0; k < n; k++) {
                    printf("%d ", arr[k]);
                }
                printf("\n");
            }
        }
        iterations++;
        printf("Array after pass %d: ", i + 1);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }

    printf("\nTotal Iterations: %d\n", iterations);
    printf("Total Comparisons: %d\n", comparisons);

    return 0;
}
