#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;


void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        return -1; 
    }
    return stack[top--];
}

char peek() {
    if (top == -1)
        return -1;
    return stack[top];
}


int precedence(char op) {
    switch(op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}


int isRightAssociative(char op) {
    return op == '^';
}


void infixToPostfix(char* infix) {
    char postfix[MAX];
    int i = 0, k = 0;
    char c;

    while ((c = infix[i++]) != '\0') {
        if (isalnum(c)) {
            postfix[k++] = c;  
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (peek() != '(' && peek() != -1) {
                postfix[k++] = pop();
            }
            pop();  
        }
        else {  
            while (precedence(peek()) > precedence(c) || 
                  (precedence(peek()) == precedence(c) && !isRightAssociative(c))) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }

    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
    printf("Postfix expression: %s\n", postfix);
}


int main() {
    char infix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}
