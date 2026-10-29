// Linear Search Implementation in C

#include <stdio.h>

int main() {
    int n, search, found = 0;

    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &search);

    printf("\n--- Linear Search ---\n");
    for (int i = 0; i < n; i++) {
        printf("Iteration %d: Comparing %d with %d\n", i + 1, arr[i], search);
        if (arr[i] == search) {
            printf("Element %d found at position %d\n", search, i + 1);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Element %d not found in the array.\n", search);
    }

    return 0;
}
