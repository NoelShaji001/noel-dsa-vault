#include <stdio.h>
#include <stdlib.h> 
int* SelectionSort(int arr[],int n){
    int i,min,j,temp;
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
    return arr;
    }
int main(){
    int i,n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int* arr=(int*)malloc(n*sizeof(int));
    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    arr=SelectionSort(arr,n);
    printf("Sorted array:\n");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    free(arr);
    return 0;
}