// Insertion Sort
    
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

void insertionSort(int arr[], int n) {
    int i, j, key;
    
    int comp = 0, itr = 0;

    printf("\n--- Insertion Sort ---\n");
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        printf("\nPass %d:\n", i);
        while (j >= 0) {
            comp++;
            printf("Comparing %d with %d\n", key, arr[j]);
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
        itr++;

        printf("Array after pass %d: ", i);
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

    insertionSort(arr, n);

    return 0;
}
