#include <stdio.h>
void mergeArray(int A[], int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = 0;
    int size = high - low + 1;
    int C[size];
    while (i <= mid && j <= high) {
        if (A[i] <= A[j])
            C[k++] = A[i++];
         else 
            C[k++] = A[j++];
    }
    while (i <= mid)
        C[k++] = A[i++];

    while (j <= high) 
        C[k++] = A[j++];

    for (int t = 0; t < size; t++) 
        A[low + t] = C[t];
}
void mergeSort(int A[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        mergeArray(A, low, mid, high);
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
    mergeSort(A, 0, n - 1);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) 
    printf("%d ", A[i]);
    return 0;
}