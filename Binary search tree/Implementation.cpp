#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node* height;
    Node(int data){
        val=data;
        left=right=nullptr;
        height=0;
    }
};
Node* root=nullptr;
int height(Node* node){
    if(node==nullptr)return -1;
    
    return node->height;
}

bool isEmpty(Node* root){
    return root==nullptr;
}

void display(){
    display(root,"Root Node:");
}

void display(Node* node,string details){
    
    if(node==nullptr)return ;
    
    cout<<details<<node->val;
    
    display(node->left,"Left child of"+to_string(node->val)+":");
    display(node->right,"Right child of"+to_string(node->val)+":");
    
}

void insert(){
    
}

Node* insert(int value,Node node){
    
    if(node==nullptr){
        node=new Node(value);
        return node;
    }
    
    if(value<node->val){
        node->left=insert(value,node->left);
    }
    if(value>node->val){
        node->right=insert(value,node->right);
    }
    
    node.height=max(height(node->left),height(node->right))+1;
    return node;
}

bool isbalanced(){
    return balanced(root);
}

bool balanced(Node* node){
    if(node==nullptr)return true;
    
    int lh=height(node->left);
    int rh=height(node->right);
    
    return abs(lh-rh)<=1 && balanced(node->left) && balanced(node->right);
}


int main() {
     
     cout<<"Enter the root Node:";
     int rootval;
     cin>>rootval;
     
     root=new Node(rootval);
    
}
