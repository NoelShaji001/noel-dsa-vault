
#include <stdio.h>
#define MAX 5

int queue[MAX];
int front=-1;
int rear=-1;
//initialising the queue
void initQ(){
    front=-1;
    rear=-1;

}
// adding elements to the queue
void enqueue(){
     printf("\n");
    int item;
    if((rear + 1) % MAX == front){
        printf("OVERFLOW!");
    }
    else{
        if(rear==MAX-1){
            rear=0;
        }else{
            rear=(rear+1)%MAX;
        }
        printf("Enter the item:");
        scanf("%d",&item);
        queue[rear]=item;
        if(front==-1)
            {front=0;}

    }
}
//deleting  elements from the queue
void dequeue(){
     printf("\n");
    int item;
    if (rear==-1){
        printf("UNDERFLOW!");

    }
    else if(front==rear){
            item=queue[front];
            printf("Deleted Item:%d",item);
            front=rear=-1;
    }else{
        item=queue[front];
        printf("Deleted Item:%d",item);
        front=(front+1)%MAX;
    }
}
//displaying the contents of the queue
void display(){
    printf("\n");
    int i = front;
if (front == -1) {
    printf("Queue is empty.\n");
} else {
    printf("Displaying the queue:\n");
    while (1) {
        printf("%d\t", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
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
            break;
        }
        else{
            printf("Invalid choice");
            
        }
    }
    return 0;
}