#include<stdio.h>

int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1;
}
int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = 7;
    int key;
    printf("Array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Enter element to search: ");
    scanf("%d", &key);
    int result = linearSearch(arr, n, key);
    if(result == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index: %d\n", result);
    }
    return 0;
}
