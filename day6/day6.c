//Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

#include <stdio.h>
int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 5};
    int n = 7;

    if (n == 0) {
        printf("No elements in the array.\n");
        return 0;
    }

    int uniqueIndex = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[uniqueIndex]) {
            uniqueIndex++;
            arr[uniqueIndex] = arr[i];
        }
    }

    // Print unique elements
    printf("Unique Elements: ");
    for (int i = 0; i <= uniqueIndex; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}