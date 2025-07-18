#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int data){
        val=data;
        left=right=nullptr;
    }
};

Node* populate(Node* node);
void display(Node* node,string indent="");
void preetyDisplay(Node* node,int level=0);
void preOrder(Node* node);
void inOrder(Node* node);
void postOrder(Node* node);
int main() {
     
     cout<<"Enter the root Node:";
     int rootval;
     cin>>rootval;
     
     Node* root=new Node(rootval);
     populate(root);
 
    //  preOrder(root);
     
    //  cout<<endl;
     
    //  inOrder(root);
     
    //  cout<<endl;
     
    //  postOrder(root);
     
    //  cout<<endl;
    
    display(root);
  
}

Node* populate(Node* node){
    
    bool left,right;
    
    cout<<"Do You want to enter left of"<<node->val<<"?(1 for yes, 0 for no)";
    cin>>left;
    
    if(left){
        cout<<"Enter the value of the left of "<<node->val<<":";
        
        int leftval;
        cin>>leftval;
        
        node->left=new Node(leftval);
        
        populate(node->left);
    }
    
    cout<<"Do You want to enter right of"<<node->val<<"?(1 for yes, 0 for no)";
    cin>>right;
    
    if(right){
        cout<<"Enter the value of the right of "<<node->val<<":";
        
        int rightval;
        cin>>rightval;
        
        node->right=new Node(rightval);
        
        populate(node->right);
    }
     
     return node;
}
void preOrder(Node* node){
    if(node==nullptr)return;
    
    cout<<node->val<<" ";
    preOrder(node->left);
    preOrder(node->right);
}
void inOrder(Node* node){
   
   if(node==nullptr)return;
    
    inOrder(node->left);
    cout<<node->val<<" ";
    inOrder(node->right);
}
void postOrder(Node* node){
    
    if(node==nullptr)return;
    
    postOrder(node->left);
    postOrder(node->right);
    cout<<node->val<<" ";
}
void display(Node* node,string indent=""){
    if(node==nullptr)return;
    cout<<indent<<node->val<<endl;
    display(node->left,indent+"\t");
    display(node->right,indent+"\t");
}

