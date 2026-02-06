//A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.
#include <stdio.h>

int main() {
    int logA[] = {1, 4, 6, 10};
    int logB[] = {2, 3, 7, 8};

    int n = 4, m = 4;
    int merged[8];

    int i = 0, j = 0, k = 0;

    // Merge both logs
    while (i < n && j < m) {
        if (logA[i] <= logB[j]) {
            merged[k++] = logA[i++];
        } else {
            merged[k++] = logB[j++];
        }
    }

    // Copy remaining entries
    while (i < n) {
        merged[k++] = logA[i++];
    }

    while (j < m) {
        merged[k++] = logB[j++];
    }

    // Print merged log
    printf("Merged Chronological Log:\n");
    for (int x = 0; x < n + m; x++) {
        printf("%d ", merged[x]);
    }

    return 0;
}
