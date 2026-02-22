//Shell Sort
#include <stdio.h>
void shellSort(int A[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = A[i];
            int j;
            for (j = i; j >= gap && A[j - gap] > temp; j -= gap) {
                A[j] = A[j - gap];
            }
            A[j] = temp;
        }
    }
}
 int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int A[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) 
    scanf("%d", &A[i]);
    shellSort(A, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) 
    printf("%d ", A[i]);
    return 0;
}
