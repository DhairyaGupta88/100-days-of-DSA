// Given an array of integers, find two elements whose sum is closest to zero.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Comparator function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void findClosestToZero(int arr[], int n) {
    // Step 1: Sort the array
    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;
    int minSum = arr[left] + arr[right];
    int minLeft = left, minRight = right;

    // Step 2: Two Pointer Approach
    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < abs(minSum)) {
            minSum = sum;
            minLeft = left;
            minRight = right;
        }

        if (sum < 0)
            left++;
        else
            right--;
    }

    printf("Two elements: %d and %d\n", arr[minLeft], arr[minRight]);
    printf("Closest sum to zero: %d\n", minSum);
}

int main() {
    int arr[] = {1, 60, -10, 70, -80, 85};
    int n = sizeof(arr) / sizeof(arr[0]);

    findClosestToZero(arr, n);

    return 0;
}
