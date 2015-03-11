/**
  Implement a function to check if a tree is balanced. For the purposes of this question, a balanced tree is
  defined to be a tree such that no two leaf nodes differ in distance from the root by more than one.
*/

#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

#define BALANCE 1
#define IMBALANCE 0
#define OTHERS -1

int dist = -1;
int max_dist = 0;
int min_dist = 0;

void cal_distance(node* root, int counter){

  if(root==NULL) return;
  counter++;
  cal_distance(root->lchild, counter);
  cal_distance(root->rchild, counter);
  if(root->lchild == NULL && root->rchild == NULL){
    printf("show node no.%d, dist:%d\n", root->data, counter);
    if(min_dist == 0){
      min_dist = counter;
    }
    if (counter > max_dist){
      max_dist = counter;
    }else if(counter < min_dist){
      min_dist = counter;
    }
    counter = 0;
  }

}

int check_balanced(node* root){

  cal_distance(root, -1);
  if(max_dist-min_dist > 1){
    max_dist = min_dist = 0;
    return IMBALANCE;
  }else{
    max_dist = min_dist = 0;
    return BALANCE;
  }

}

node* test_imbalcase(){

  node* root = NULL;
  insert(&root, 20);
  insert(&root, 10);
  insert(&root, 21);
  insert(&root, 9);
  insert(&root, 14);
  insert(&root, 8);
  insert(&root, 12);
  insert(&root, 15);
  insert(&root, 5);
  return root;

}

node* test_balcase(){

  node* root = NULL;
  insert(&root, 20);
  insert(&root, 10);
  insert(&root, 21);
  insert(&root, 9);
  return root;

}

void main(){

  printf("[Imbalanced Case Demo]\n");
  node* imbal_root = test_imbalcase();
  int result = check_balanced(imbal_root);
  printf("Result is: %d (0:imbalanced, 1:balanced)\n", result);
  release(imbal_root);

  printf("[Balanced Case Demo]\n");
  node* bal_root = test_balcase();
  result = check_balanced(bal_root);
  printf("Result is: %d (0:imbalanced, 1:balanced)\n", result);
  release(bal_root);

}
