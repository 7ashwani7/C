// Heap Deletion
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyDown(int heap[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] > heap[largest])
        largest = left;

    if (right < n && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapifyDown(heap, n, largest);
    }
}

int deleteRoot(int heap[], int *n) {
    if (*n <= 0) return -1;

    int rootValue = heap[0];
    heap[0] = heap[*n - 1];
    *n = *n - 1;

    heapifyDown(heap, *n, 0);

    return rootValue;
}

void printHeap(int heap[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    int heap[100] = {40, 30, 15, 10, 20};
    int n = 5;

    printf("Original Heap: ");
    printHeap(heap, n);

    int removed = deleteRoot(heap, &n);
    printf("Deleted element: %d\n", removed);

    printf("Heap after deletion: ");
    printHeap(heap, n);

    return 0;
}