#include<stdio.h>
char postfix[10];
char stack[10];
int prec(char p){
    if(p=="*"||"/"){
        return 3;

    }else if(p=="+"||"-"){
        return 2;
    }else if(p=="**"){
        return 4;
    }
}
int main(){
    int i;
    char str;
    printf("Enter the equation:\n");
    scanf("%s",str);
    printf("\nInfix Expression:%d",str);
    for(i=0;str[i]!='\0';i++);
    int len=i;
    while(str[i]!='\0'){
        if(str[i]!="+"||"-"||"*"||"/"||"^"||"("||")"){
            static int j=0;
            postfix[j]=str[i];
            j++;

        }
        else{
            prec()

        }
    }

}