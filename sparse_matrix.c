#include<stdio.h>
int main(){
    int i,j,k=1,n,m,l=1;
    printf("Enter the no and columns for  the matrices:");
    scanf("%d%d",&n,&m);
     int a[n][m],b[n][m],c[n*m][3],d[n*m][3],e[n*m][3];
     
    printf("enter elements for matrix a\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("enter elements for matrix b\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&b[i][j]);
        }
    }
    
//sparse calc for matrix a
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(a[i][j]!=0){
                c[k][0]=i;
                c[k][1]=j;
                c[k][2]=a[i][j];
                k++;

            }
            
        }
    }
    c[0][0]=n;
    c[0][1]=m;
    c[0][2]=k-1;
    printf("Displaying the sparse matrix representation of a\n");
     for(i=0;i<k;i++){
        for(j=0;j<3;j++){
            printf("%d",c[i][j]);
        }
        printf("\n");
        }
    //sparse calc for matrix b
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(b[i][j]!=0){
                d[l][0]=i;
                d[l][1]=j;
                d[l][2]=b[i][j];
                l++;

            }
            
        }
    }
    d[0][0]=n;
    d[0][1]=m;
    d[0][2]=l-1;
    printf("Displaying the sparse matrix representation of b\n");
    for(i=0;i<l;i++){
        for(j=0;j<3;j++){
            printf("%d",d[i][j]);
        }
        printf("\n");
    }
    printf("addition of sparse matrix\n");
    int p = 1, q = 1, r = 1;
    e[0][0] = n;
    e[0][1] = m;

    while (p <= c[0][2] && q <= d[0][2]) {
        if (c[p][0] == d[q][0] && c[p][1] == d[q][1]) {
            int sum = c[p][2] + d[q][2];
            if (sum != 0) {
                e[r][0] = c[p][0];
                e[r][1] = c[p][1];
                e[r][2] = sum;
                r++;
            }
            p++;
            q++;
        } else if (c[p][0] < d[q][0] || (c[p][0] == d[q][0] && c[p][1] < d[q][1])) {
            e[r][0] = c[p][0];
            e[r][1] = c[p][1];
            e[r][2] = c[p][2];
            r++;
            p++;
        } else {
            e[r][0] = d[q][0];
            e[r][1] = d[q][1];
            e[r][2] = d[q][2];
            r++;
            q++;
        }
    }
    while (p <= c[0][2]) {
        e[r][0] = c[p][0];
        e[r][1] = c[p][1];
        e[r][2] = c[p][2];
        r++;
        p++;
    }
    while (q <= d[0][2]) {
        e[r][0] = d[q][0];
        e[r][1] = d[q][1];
        e[r][2] = d[q][2];
        r++;
        q++;
    }
    e[0][2] = r - 1;  
    for (i = 0; i <= e[0][2]; i++) {
        printf("%d %d %d\n", e[i][0], e[i][1], e[i][2]);
    }
  
int t[r][3];  
t[0][0] = e[0][1];  
t[0][1] = e[0][0];  
t[0][2] = e[0][2];  


for(i = 1; i <= e[0][2]; i++) {
    t[i][0] = e[i][1];  
    t[i][1] = e[i][0];  
    t[i][2] = e[i][2];  
}




printf("Transpose of the resulting sparse matrix:\n");
for(i = 0; i <= t[0][2]; i++) {
    printf("%d %d %d\n", t[i][0], t[i][1], t[i][2]);
}
return 0;
}


