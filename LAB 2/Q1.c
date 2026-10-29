// Selection Sort

#include <stdio.h>

void inputArray(int arr[], int n) {
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int n) {
    int comp = 0, itr = 0;
    int min;

    printf("\n--- Selection Sort ---\n");
    
    for (int i = 0; i < n - 1; i++) {
        min = i;
        printf("\nPass %d:\n", i + 1);
        for (int j = i + 1; j < n; j++) {
            comp++;
            printf("Comparing arr[%d]=%d with arr[%d]=%d\n", min, arr[min], j, arr[j]);
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        // Swap if needed
        if (min != i) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
        itr++;
        printf("Array after pass %d: ", i + 1);
        printArray(arr, n);
    }

    printf("\nFinal Sorted Array: ");
    printArray(arr, n);
    printf("Total Iterations: %d\n", itr);
    printf("Total Comparisons: %d\n", comp);
}

int main() {
    int n;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    int arr[n];
    inputArray(arr, n);

    selectionSort(arr, n);

    return 0;
}
