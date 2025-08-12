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
    
        return rear==-1;

}
//check if the queue is full
int isFull(){
    return rear==MAX-1;

}
// adding elements to the queue
void InsertFront(){
     printf("\n");
    int item;
    if(front==0&&rear==MAX-1){
        printf("OVERFLOW!");
    }
    else{
        front=front-1;
        printf("Enter the data:\n");
        scanf("%d",&item);
        queue[front]=item;

    }
}
//deleting  elements from the queue
void InsertBack(){
     printf("\n");
    int item;
    if (front==0&&rear==MAX-1){
        printf("OVERFLOW!");

    }
    else{
        rear=rear+1;
       printf("Enter the data:\n");
        scanf("%d",&item);
        queue[rear]=item;
    }
}
void DeleteFront(){
     printf("\n");
    int item;
    if(front==-1){
        printf("UNDERFLOW!");
        return;
    }
    else{
        item=queue[front];
        printf("Deleted Item=%d",item);

    }
    if(front==rear){
        front=rear=-1;
    }else{
        front=front+1;
    }
}
void DeleteBack(){
     printf("\n");
    int item;
    if (rear==-1){
        printf("UNDERFLOW!");
        return;

    }
    else{
        item=queue[rear];
        printf("Deleted Item at Back:%d",item);
    }
    if(front==rear){
        front=rear=-1;
    }else{
        rear=rear-1;
    }
        
}
//displaying the contents of the queue
void display(){
    printf("\n");
    printf("Displaying the queue at front:\n");
    int i;
    for(i=front;i<=rear;i++){
        printf("%d\t",queue[i]);
    }
}
//main fuction where we operate enqueue,dequeue,amd diaplaying the queue
int main(){
    initQ();
    int choice;
    printf("Operations:\n1)InsertFront\n2)InsertBack\n3)DeleteFront\n4)DeleteFront\n5)display the queue\n6)Exit\n");
    while(1){
         printf("Enter your option:\n");
    scanf("%d",&choice);
     printf("\n");
        if(choice==1){
            InsertFront();
             printf("\n");

        }
        else if(choice==2){
            InsertBack();
             printf("\n");
            
        }
        else if(choice==3){
            DeleteFront();
            printf("\n");
        }
        else if(choice==4){
           DeleteBack();
           printf("\n");
        }
        else if(choice==5){
            display();
             printf("\n");
        }
        else if(choice==6){
            printf("Exiting the Queue......");
            break;
        }else{
            printf("Invalid Choice!!");
        }
    }
    return 0;
}