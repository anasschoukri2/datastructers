#include <stdio.h>
#include<stdlib.h>
typedef struct Node{
  int data;
  struct Node *left,*right;
}node;
node * insert(node * root,int x){ 
    node * n=(node *)malloc(sizeof (node));
    n->data=x;
    n->right=n->left=NULL;
    if(root==NULL)return n;
    if(x>root->data)root->right=insert(root->right, x);
    if(x<root->data)root->left=insert(root->left,x);
    return root;
}
node * search(node * root, int x){
    if(root==NULL)return NULL;
    if(root->data==x)return root;
    if(x>root->data)return search(root->right, x);
    if(x<root->data)return search(root->left,x);
    return NULL;
}
node * Delete(node * root,int key){
            if (root == NULL)
                return NULL;
            if (root->val > key)
                root->left = deleteNode(root->left, key);
            else if (root->val < key)
                root->right = deleteNode(root->right, key);
            else {
                if (root->left == NULL)return root->right;
                if (root->right == NULL)return root->left;
                TreeNode* y = root->right;
                while (y->left != NULL)
                    y = y->left;
                root->val = y->val;
                root->right = deleteNode(root->right, y->val);
            }
            return root;
}
int main(void) {
  node* root;
  root=(node*)malloc(sizeof(node));
  root=insert(root, 0);
  root= insert(root, 2);
  root=insert(root, 1);
  root=insert(root, 3);
  root=Delete(root,3 );
  node* found=search(root,3);
  if(found==NULL){
    printf("does't exist\n");
  }
  else printf("found\n");
  
  return 0;
}
