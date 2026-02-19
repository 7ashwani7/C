#include <stdio.h>
void selectionSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[min])
                min = j;
        }
        // Swap
        int temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }
}

int main() {
    int A[] = {64, 25, 12, 22, 11};
    int n = sizeof(A) / sizeof(A[0]);
    selectionSort(A, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);

    return 0;
}