// You are given a rectangular matrix of integers. Starting from the outer boundary, traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited

#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    // Input matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    while(top <= bottom && left <= right) {

        // 1. Left to Right
        for(int i = left; i <= right; i++)
            printf("%d ", matrix[top][i]);
        top++;

        // 2. Top to Bottom
        for(int i = top; i <= bottom; i++)
            printf("%d ", matrix[i][right]);
        right--;

        // 3. Right to Left
        if(top <= bottom) {
            for(int i = right; i >= left; i--)
                printf("%d ", matrix[bottom][i]);
            bottom--;
        }

        // 4. Bottom to Top
        if(left <= right) {
            for(int i = bottom; i >= top; i--)
                printf("%d ", matrix[i][left]);
            left++;
        }
    }

    return 0;
}
