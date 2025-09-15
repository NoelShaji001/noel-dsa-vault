#include<stdio.h>
#include<stdlib.h>
void initialisation(){
    struct node{
        int data;
        struct node *next;
    }
}
struct node* createNode(int item){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data = item;
    newNode->next = NULL;
    return newNode;

}
void Traverse(struct node* head,struct node* temp){
    int count=0;
    temp = head;
    while(temp!=NULL){
        printf("%d",temp.data);
        temp=temp.next;
        count++
    
    }
}void Traverse(struct node* head,struct node* temp){
    int count=0;
    temp = head;
    while(temp!=NULL){
        printf("%d",temp.data);
        temp=temp.next;
        count++
    
    }
    printf("NULL");
}



struct node* InsertatBEG(struct node* head){
    int item;
    printf("Enter the data to insert at the beginning: ");
    scanf("%d",&item);
    struct node* newNode=createNode(item);
    newnode.next=head;
    head=newNode;
    return newNode;
}
struct node* InsertatEND(struct node* head){
    int item;
    printf("Enter the data to be  inserted at the end: ");
    scanf("%d",&item);
    struct node* temp;
    struct node* newNode=createNode(item);
    newNode.next=NULL;
    temp=head;
    while(temp.next!=0){
        temp=temp.next;
    
    }
    temp.next=newNode;
    return newNode;
}
struct node* InsertatAnyPOS(struct node* head){
    int pos,item;
    printf("Enter the position you want to insert data:");
    scanf("%d",&pos);
    printf("Enter the data:");
    scanf("%d",&item);
    struct node* newNode=createNode(item);
    if (position == 0) {
        newNode->next = head;
        return newNode;
    }
    struct node* temp;
     int i;
    for (i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position %d is out of bounds.\n", position);
        free(newNode);
        return head;  
    }
     newNode->next = temp->next;
    temp->next = newNode;

    return head;
}
    struct node* DeleteAtBEG(struct node* head){
        struct node* temp;
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    else if (head->next == NULL) {
        free(head);
        return NULL;
    }
    else{
        temp=head;
        head=head.next;
        free(temp);
    }

    return head;
    }
    struct node* DeleteAtEND(struct node* head){
        struct node* prevnode;
        struct node* temp;
        temp=head;
        while(temp.next!=0){
            prevnode=temp;
            temp=temp.next;
        }
        if(temp==head){
            head=0;
        }
        else{
            prevnode.next=0;
        }
        free(temp);
        return head;

        }
        struct node* DeleteAtAnyPOS(struct node* head){
            struct node* temp;
            int pos,i=1;
            temp=head;
            printf("%d",&pos);
            while (i<pos-1){
                temp=temp.next;
                i++;
            }
            struct node* nextNode=temp.next;
            temp.next=nextNode.next;
            free(nextNode);
            return head;
            
        }
int main(){
    int choice;
    printf("Operations\n
        1)InsertAtBeginning\n
        2)InsertAtEnd\n
        3)InsertAtAnyPos\n
        4)DeleteAtBeginning\n
        5)DeleteAtEnd\n
        6)DeleteAtAnyPos\n
        7)Display\n
        8)Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
}