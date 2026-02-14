#include<stdio.h>

int BinarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return -1;
}
int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;
    int key;
    printf("Enter a number to search: ");
    scanf("%d", &key);
    int result = BinarySearch(arr, n, key);
    if(result == -1) {
        printf("Element not found\n");
    }
    else {
        printf("Element found at index: %d\n", result);
    }
    return 0;
}
