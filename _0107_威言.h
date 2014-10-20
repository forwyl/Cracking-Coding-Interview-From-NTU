#ifndef SETMATRIXVALUE_H_INCLUDED
#define SETMATRIXVALUE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
1.7 Write an algorithm such that if an element in an MxN matrix is 0, its entire
 row and column is set to 0.
**/

#define N 10
void setMatrixValue();
void input();
int i, j, m, n, row, col;
int **a;

void input(){

    printf("Please determine the row dimension of the matrix. It must be smaller than %dand bigger than 1: \n",N);
    scanf("%d",&m);
    if(m<=1 || m>N){
        printf("input error\n");
        exit(0);
    }
    printf("Please determine the column dimension of the matrix. It must be smaller than %dand bigger than 1: \n",N);
    scanf("%d",&n);
    if(n<=1 || n>N){
        printf("input error\n");
        exit(0);
    }

    a = (int **)malloc(m*sizeof(int *));
    for(i=0; i<m; i++)
      a[i]=(int *)malloc(n*sizeof(int));

    for(i=0;i<m;i++){
       for(j=0;j<n;j++){
           printf("a[%d][%d]=",i,j);
           scanf("%d",&a[i][j]);
           printf("\n");
       }
    }
    printf("The input matrix is:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }

    printf("Please determine the valid row index of the matrix:\n");
    scanf("%d",&row);
    if(row < 0 || row > m){
        printf("input error\n");
        exit(0);
    }
    printf("Please determine the valid column index of the matrix:\n");
    scanf("%d",&col);
    if(col < 0 || col > n){
        printf("input error\n");
        exit(0);
    }

}

void setMatrixValue(){

    input();

    for(i=0; i<n; i++)
        a[row][i] = 0;
    for(i=0; i<m; i++)
        a[i][col] = 0;

    printf("The ouput matrix is:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }

    free(a);

}
#endif // SETMATRIXVALUE_H_INCLUDED
