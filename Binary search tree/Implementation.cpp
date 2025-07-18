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

int main() {
     
     cout<<"Enter the root Node:";
     int rootval;
     cin>>rootval;
     
     root=new Node(rootval);
    
}

