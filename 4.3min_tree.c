/**
Given a sorted (increasing order) array, write an algorithm to create a binary tree with minimal height.
**/

#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

int find_mid(int start, int end){
  int result = (end-start+1)/2;
  return start+result;
}

node* ary_mintree(node** root, int start, int end, int* ary_ptr){

  int mid = find_mid(start, end);
//  printf("MID=%d, start=%d, end=%d\n", mid, start, end);
  *root = (node*)malloc(sizeof(node));
  (*root)->data = *(ary_ptr+mid);
  (*root)->lchild = (*root)->rchild = NULL;

  if(mid-1 >= start){
    ary_mintree(&(*root)->lchild, start, mid-1, ary_ptr);
  }

  if(end >= mid+1){
    ary_mintree(&(*root)->rchild, mid+1, end, ary_ptr);
  }

  return *root;

}

void main(){

  int ary[] = {1,2,3,4};
  int len = sizeof(ary)/sizeof(int);
  node* root = NULL;

  root = ary_mintree(&root, 0, len-1, ary);
  printf("Show tree:\n");
  print_preorder(root);
  printf("Height:%d\n", max_height(root));

  release(root);

}
