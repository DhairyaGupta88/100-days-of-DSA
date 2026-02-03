//Implement linear search to find key k in an array. Count and display the number of comparisons performed.
#include <stdio.h>
int main() {
    int n, k, arr[100]; // assuming maximum size is 100
    int comparisons = 0;
    int found = 0;

    // Input number of elements
    scanf("%d", &n);

    // Input array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input key to search
    scanf("%d", &k);

    // Linear search for key k
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == k) {
            found = 1;
            break;
        }
    }

    // Display result
    if (found) {
        printf("Element found\n");
    } else {
        printf("Element not found\n");
    }
    printf("Number of comparisons: %d\n", comparisons);

    return 0;
}