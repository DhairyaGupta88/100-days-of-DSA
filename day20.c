//Given an array of integers, count the number of subarrays whose sum is equal to zero.
#include <stdio.h>

#define MAX 1000

int countZeroSumSubarrays(int arr[], int n) {
    int prefixSum = 0;
    int count = 0;

    // Hash array to store frequency of prefix sums
    int hash[2 * MAX + 1] = {0};  
    int offset = MAX;  // To handle negative sums

    hash[offset] = 1;  // To handle prefixSum = 0 case

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // If this prefixSum seen before, add its frequency
        count += hash[prefixSum + offset];

        // Increase frequency
        hash[prefixSum + offset]++;
    }

    return count;
}

int main() {
    int arr[] = {3, 4, -7, 3, 1, 3, -4, -2, -2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = countZeroSumSubarrays(arr, n);
    printf("Number of zero sum subarrays: %d\n", result);

    return 0;
}