// Merge Sort

#include <stdio.h>

int comparisons = 0, iterations = 0;


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void merge(int arr[], int left, int mid, int right, int temp[]) {
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        comparisons++;
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];         
    }

    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];

    for (int x = left; x <= right; x++)
        arr[x] = temp[x];

    iterations++;
    printf("After merge pass %d : ", iterations);
    printArray(arr, right + 1);
}


void mergeSort(int arr[], int left, int right, int temp[]) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid, temp);
        mergeSort(arr, mid + 1, right, temp);
        merge(arr, left, mid, right, temp);
    }
}


void takeInput(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}


int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], temp[n];
    takeInput(arr, n);

    mergeSort(arr, 0, n - 1, temp);
    printf("Sorted Array: ");
    printArray(arr, n);
    printf("Total Comparisons: %d\n", comparisons);
    printf("Total Iterations (Merge Passes): %d\n", iterations);

    return 0;
}