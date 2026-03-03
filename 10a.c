// Heap Insetion
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int heap[], int index) {
    int parent = (index - 1) / 2;

    if (index > 0 && heap[index] > heap[parent]) {
        swap(&heap[index], &heap[parent]);
        heapifyUp(heap, parent);
    }
}

int insertNode(int heap[], int *n, int value) {
    heap[*n] = value;
    *n = *n + 1;
    
    heapifyUp(heap, *n - 1);
}

void printHeap(int heap[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    int heap[100];
    int n = 0;

    insertNode(heap, &n, 10);
    insertNode(heap, &n, 20);
    insertNode(heap, &n, 15);
    insertNode(heap, &n, 30);
    insertNode(heap, &n, 40);

    printf("Max-Heap array: ");
    printHeap(heap, n);

    return 0;
}