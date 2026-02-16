// Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.
#include <stdio.h>

int main() {
    int n, m;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &n, &m);

    int matrix[n][m];

    printf("Enter matrix elements:\n");

    // Input matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int sum = 0;

    // Calculate primary diagonal sum
    for(int i = 0; i < n && i < m; i++) {
        sum += matrix[i][i];
    }

    printf("Sum of primary diagonal = %d\n", sum);

    return 0;
}
