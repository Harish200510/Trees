#include<bits/stdc++.h>
using namespace std;

void preorder(Node* root){
     
     if(root==nullptr)return;
     
     cout<<node->val;
     
     preorder(node->left);
     preorder(node->right);
     
}

Where is it used:
      ->Used for math evaluation
      ->making a copy of tree
      ->When you have a array or string and want to convert to binary tree or vice versa you can use this traversal (serialisation of array/string)
