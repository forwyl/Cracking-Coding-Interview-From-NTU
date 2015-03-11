/**
Given a directed graph, design an algorithm to find out whether there is a route between two nodes.
**/

#include <stdlib.h>
#include <stdio.h>
#define LEN 6

int adj_matrix[LEN][LEN];
int visit[LEN];

void init(){

  int i, j;
  for(i=0; i<LEN; i++){
    visit[i] = 0;
  }
  for(i=0; i<LEN; i++){
    for(j=0; j<LEN; j++){
      adj_matrix[i][j] = 0;
    }
  }
  /* graph case*/
  adj_matrix[0][1] = adj_matrix[1][2] = adj_matrix[2][3] = adj_matrix[0][3]
  = adj_matrix[2][4] = adj_matrix[1][5] = adj_matrix[1][4] = 1;

}

int checkroute(int u, int v){

  int i ;
  visit[u] = 1;
  for(i=0; i<LEN; i++){
    if(adj_matrix[u][i] && !visit[i]){
      printf("go %d \n", i);
      checkroute(i, v);
    }
    if(visit[i] && i==v){
      return 1;
    }
  }

  return 0;

}

void main(){

  init();
  printf("[Positive Case Demo]\n");
  int result = checkroute(1, 5);
  printf("result:%d  (1:yes, 0:no) \n", result);
  init();
  printf("[Negative Case Demo]\n");
  result = checkroute(2, 5);
  printf("result:%d  (1:yes, 0:no) \n", result);

}
