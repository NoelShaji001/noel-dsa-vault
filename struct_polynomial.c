#include<stdio.h>

struct Term {
  int coeff;
  int exp;
};

int main() {
  struct Term P1[100], P2[100], Result[100];
  int m, n, custom = 0;
  int i, j, k;
  
  printf("Enter the number of terms in first polynomial: ");
  scanf("%d", &m);
  printf("Enter the terms in descending order of exponents (coeff exp): \n");
  
  for(i = 0; i < m; i++) {
    printf("Term %d: ", i+1);
    scanf("%d %d", &P1[i].coeff, &P1[i].exp);
  }
  
  printf("\nEnter the number of terms in second polynomial: ");
  scanf("%d", &n);
  printf("Enter the terms in descending order of exponents (coeff exp): \n");
  
  for(i = 0; i < n; i++) {
    printf("Term %d: ", i+1);
    scanf("%d %d", &P2[i].coeff, &P2[i].exp);
  }
  
  i = 0; j = 0; k = 0;
  
  while(i < m && j < n) {
    if(P1[i].exp == P2[j].exp) {
      Result[k].coeff = P1[i].coeff + P2[j].coeff;
      Result[k].exp = P1[i].exp;
      i++; j++; k++;
    }
    else if(P1[i].exp > P2[j].exp) {
      Result[k] = P1[i];
      i++; k++;
    }
    else {
      Result[k] = P2[j];
      j++; k++;
    }
  }
  
  while(i < m) {
    Result[k] = P1[i];
    i++; k++;
  }
  
  while(j < n) {
    Result[k] = P2[j];
    j++; k++;
  }
  
  custom = k;
  
  printf("\nThe sum of first polynomial and second polynomial is \n");
  
  for(i = 0; i < custom; i++) {
    if(Result[i].coeff == 0)
      continue;
    
    if(i > 0 && Result[i].coeff > 0)
      printf(" + ");
      
    if(Result[i].exp == 0)
      printf("%d", Result[i].coeff);
      
    else if(Result[i].exp == 1)
      printf("%dx", Result[i].coeff);
      
    else 
      printf("\n%dx^%d", Result[i].coeff, Result[i].exp);
  }
  
  printf("\n");
  
  return 0;
}