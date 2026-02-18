#include <stdio.h>

void bubbleSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                // swap
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

int main() {
    int A[] = {64, 25, 12, 22, 11};
    int n = sizeof(A) / sizeof(A[0]);
    bubbleSort(A, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);

    return 0;
}