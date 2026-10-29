//  Binary Search

#include <stdio.h>

int main() {
    int n, search, low, high, mid, found = 0, iteration = 0;

    printf("Enter number of elements in sorted array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &search);

    low = 0;
    high = n - 1;

    printf("\n--- Binary Search ---\n");
    while (low <= high) {
        mid = (low + high) / 2;
        iteration++;
        printf("Iteration %d: low=%d, high=%d, mid=%d, arr[mid]=%d\n",
               iteration, low, high, mid, arr[mid]);

        if (arr[mid] == search) {
            printf("Element %d found at position %d\n", search, mid + 1);
            found = 1;
            break;
        } else if (arr[mid] < search) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!found) {
        printf("Element %d not found in the array.\n", search);
    }

    return 0;
}
