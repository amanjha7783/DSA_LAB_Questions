//  Quick Sort 

#include <stdio.h>

int comparisons = 0, iterations = 0;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// int partition(int arr[], int low, int high, int n) {
//     int pivot = arr[high];
//     int i = low - 1;
//     printf("\nPartitioning with pivot = %d\n", pivot);

//     for (int j = low; j < high; j++) {
//         comparisons++;
//         printf("Comparing arr[%d]=%d with pivot %d\n", j, arr[j], pivot);
//         if (arr[j] <= pivot) {  // Move smaller to left
//             i++;
//             int temp = arr[i];
//             arr[i] = arr[j];
//             arr[j] = temp;
//             printf("Swapped: ");
//             printArray(arr, n);
//         }
//     }

//     int temp = arr[i + 1]; // larger to right
//     arr[i + 1] = arr[high];
//     arr[high] = temp;

//     printf("Placed pivot -> ");
//     printArray(arr, n);
//     iterations++;

//     return i + 1;
// }

// void quickSort(int arr[], int low, int high, int n) {
//     if (low < high) {
//         int pi = partition(arr, low, high, n);
//         quickSort(arr, low, pi - 1, n);  // Repeat for left
//         quickSort(arr, pi + 1, high, n); // Repeat for right
//     }
// }


int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    int temp;

    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("\n--- Quick Sort ---\n");
    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // printf("\nFinal Sorted Array: ");
    // printArray(arr, n);
    // printf("Total Iterations: %d\n", iterations);
    // printf("Total Comparisons: %d\n", comparisons);

    return 0;
}
