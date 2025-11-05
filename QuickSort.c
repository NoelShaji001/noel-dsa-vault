#include <stdio.h>    
#include <stdlib.h>
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int lb, int ub) {
    int pivot = arr[ub];
    int i = (lb - 1);
    for (int j = lb; j < ub; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    
    }
    swap(&arr[i + 1], &arr[ub]);
    return (i + 1);
}
void QuickSort(int arr[], int lb, int ub) {
    if (lb < ub) {
        int pivotIndex = partition(arr, lb, ub);
        QuickSort(arr, lb, pivotIndex - 1);
        QuickSort(arr, pivotIndex + 1, ub);
    }
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main() {
    int i, n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int* arr = (int*) malloc(n * sizeof(int));
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Before QuickSort:\n");
    printArray(arr, n);
    QuickSort(arr, 0, n - 1);
    printf("Sorted array(QUICK):\n");
    printArray(arr, n);
    free(arr);
    return 0;
}
