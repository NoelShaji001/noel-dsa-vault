#include <stdio.h>
#include <stdlib.h> 
int main(){
    int n,i,s=0,e,key,m,flag=0;
    printf("Enter the number of elements in the array:");
    scanf("%d",&n);
    printf("Enter the array elements in sorted way(ASCENDING):");
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    printf("Enter the element you want to search:");
    scanf("%d",&key);
    e=n-1;
    while(s<=e){
        m=(s+e)/2;
        if(arr[m]==key){
            printf("Element found at index %d\n",m);
            flag=1;
            break;
        }
        else if(arr[m]<key){
            s=m+1;
        }
        else{
            e=m-1;

        } 
        
    }
    if (flag==0){
        printf("Element not found\n");
    }else{
        printf("Search operation successful\n");
    }
    return 0;
}