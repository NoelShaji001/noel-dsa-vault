#include <stdio.h>  
#include <stdlib.h>
int* BubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return arr;
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
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
    printf("Before BubbleSort:\n");
    printArray(arr, n);
    BubbleSort(arr, n);
    printf("Sorted array(BUBBLE):\n");
    printArray(arr, n);
    free(arr);
    return 0;

}
