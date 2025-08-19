#include<stdio.h>
#define MAX 10
int Stack[MAX];
int TOP=-1;
 int isFull(){
    return TOP==MAX-1;

 }
int  isEmpty(){
    return TOP==-1;
}
void PUSH(){
    int item;
    if(isFull()){
        printf("OVERFLOW!!!!\n");
    }else{
        TOP++;
        printf("Enter the data to be added:\n");
        scanf("%d",&item);
        Stack[TOP]=item;
    }
}
void POP(){
    int item;
    if(isEmpty()){
        printf("UNDERFLOW!!!!\n");
    }else{
        item=Stack[TOP];
        printf("Deleted  Item:%d\n",item);
        TOP--;
    }
}
void Display(){
    for(int i=0;i<=TOP;i++){
        printf("%d",Stack[i]);
        printf("\n");
    }
}
int  main(){
    int choice;
    printf("Operations:\n1)PUSH\n2)POP\n3)Display\n4)Exit");
    while(1){
         printf("\nEnter your  operation:");
    scanf("%d",&choice);
    if(choice==1){
        PUSH();
    }
    else if(choice==2) {
        POP();

    }else if(choice==3){
        Display();
    }else if (choice==4){
        break;
    }else{
        printf("Invalid Choice");
    }
}
return 0;
}
