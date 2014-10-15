#ifndef ROTATEMATRIX90_H_INCLUDED
#define ROTATEMATRIX90_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10
void rotateMatrix90();

void rotateMatrix90(){

    int i, j, n, floor, ceiling, temp;
    int a[N][N];

    printf("Please determine the dimension of the matrix. It must be smaller than %d\n",N);
    scanf("%d",&n);
    if(n>N){
        printf("input error\n");
        exit(0);
    }
    for(i=0;i<n;i++){
       for(j=0;j<n;j++){
           printf("a[%d][%d]=",i,j);
           scanf("%d",&a[i][j]);
           printf("\n");
       }
    }
    printf("The input matrix is:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }

    floor = n/2;
    ceiling = (n+1)/2;
    for(i=0; i<floor; i++){
        for(j=0; j<ceiling; j++){
            temp = a[i][j];
            a[i][j] = a[j][n-1-i];
            a[j][n-1-i] = a[n-1-i][n-1-j];
            a[n-1-i][n-1-j] = a[n-1-j][i];
            a[n-1-j][i] = temp;

        }
    }

    printf("The matrix after rotated 90 degrees is:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }

}

#endif // ROTATEMATRIX90_H_INCLUDED
