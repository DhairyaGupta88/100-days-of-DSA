// Given an array of n integers, reverse the array in-place using two-pointer approach.
#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    int left = 0, right = n - 1;
    int temp;

    while (left < right) {
        // swap
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }

    // print reversed array
    printf("Reversed Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
