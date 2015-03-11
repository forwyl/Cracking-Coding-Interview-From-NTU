typedef struct node{
    int data;
    struct node * lchild, * rchild;
}node;

void insert(node** leaf, int data){
  if(!(*leaf)){
    *leaf = (node*)malloc(sizeof(node));
    (*leaf)->lchild = (*leaf)->rchild = NULL;
    (*leaf)->data = data;
    //printf("%d\n", (*leaf)->data);
    return;
  }else if(data < (*leaf)->data){
    insert(&(*leaf)->lchild, data);
  }else if(data > (*leaf)->data){
    insert(&(*leaf)->rchild, data);
  }
}

void print_preorder(node* root){
  if(root){
    printf("Tree %d\n", root->data);
    print_preorder(root->lchild);
    print_preorder(root->rchild);
  }
}

void release(node* root){
  if(!root) return;
  release(root->lchild);
  release(root->rchild);
  free(root);
}

int max_height(node* root){
  if(root==NULL) return 0;
  int lheight = max_height(root->lchild);
  int rheight = max_height(root->rchild);
  if(lheight > rheight){
    return lheight+1;
  }else{
    return rheight+1;
  }
}


