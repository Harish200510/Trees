#include<bits/stdc++.h>
using namespace std;

void inorder(Node* root){
     
     if(root==nullptr)return;
     
     inorder(node->left);
     
     cout<<node->val;
     
     inorder(node->right);
     
}

Where is it used:
      ->In BST tree if you apply this traversal your node will be displayed in sorted manner
     
