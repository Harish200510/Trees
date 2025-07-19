#include<bits/stdc++.h>
using namespace std;

void postorder(Node* root){
     
     if(root==nullptr)return;
     
     postorder(node->left);
     
     postorder(node->right);
     
     cout<<node->val;
     
}

Where is it used:
      ->To delete a Binary tree
      ->To calculate something bottom of the tree
     
