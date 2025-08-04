#include <stdio.h>
#define MAX 100

int queue[MAX];
int front=0;
int rear=-1;
//initialising the queue
void initQ(){
    front=0;
    rear=-1;

}
//check if the queue is empty
int isEmpty(){
    
        return front==-1;

}
//check if the queue is full
int isFull(){
    return rear==MAX-1;

}
// adding elements to the queue
void enqueue(){
     printf("\n");
    int item;
    if(isFull()){
        printf("OVERFLOW!");
    }
    else{
        rear=rear+1;
        printf("Enter the data:\n");
        scanf("%d",&item);
        queue[rear]=item;

    }
}
//deleting  elements from the queue
void dequeue(){
     printf("\n");
    int item;
    if (rear==-1){
        printf("UNDERFLOW!");

    }
    else{
        item=queue[front];
        printf("Deleted item:%d",item);
        front+=1;
    }
}
//displaying the contents of the queue
void display(){
    printf("\n");
    printf("Displaying the queue:\n");
    int i;
    for(i=front;i<=rear;i++){
        printf("%d\t",queue[i]);
    }
}
//main fuction where we operate enqueue,dequeue,amd diaplaying the queue
int main(){
    initQ();
    int choice;
    printf("Operations:\n1)Enqueue\n2)Dequeue\n3)Display the Queue\n4)Exit.\n");
    while(1){
         printf("Enter your option:\n");
    scanf("%d",&choice);
     printf("\n");
        if(choice==1){
            enqueue();
             printf("\n");

        }
        else if(choice==2){
            dequeue();
             printf("\n");
            
        }
        else if(choice==3){
            display();
             printf("\n");
            
        }
        else if(choice==4){
            printf("Displaying the final queue:\n");
            display();
            break;
        }
        else{
            printf("Invalid choice");
            
        }
    }
    return 0;
}

