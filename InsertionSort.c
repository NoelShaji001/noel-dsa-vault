#include <stdio.h>  
#include <stdlib.h>
int* InsertionSort(int arr[], int n){
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return arr;
}
int main(){
    int i, n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int* arr=(int*) malloc(n* sizeof(int));
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    arr = InsertionSort(arr, n);
    printf("Sorted array(INSERTION):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}