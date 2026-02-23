//Radix Sort
#include <stdio.h>
int getMax(int A[], int n) {
    int max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}
void countSort(int A[], int n, int exp) {
    int output[n];
    int count[10] = {0};
    for (int i = 0; i < n; i++)
        count[(A[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[(A[i] / exp) % 10] - 1] = A[i];
        count[(A[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
        A[i] = output[i];
}
void radixSort(int A[], int n) {
    int m = getMax(A, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(A, n, exp);
} 
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int A[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) 
    scanf("%d", &A[i]);
    radixSort(A, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) 
    printf("%d ", A[i]);
    return 0;
}