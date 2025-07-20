#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    int height;
    Node(int data){
        val=data;
        left=right=nullptr;
        height=0;
    }
};
Node* root=nullptr;

//this function will return the height of that specific node which we already stored
int height(Node* node){
    if(node==nullptr)return -1;
    
    return node->height;
}

//Logic to display the values
void display(Node* node,string details){
    
    if(node==nullptr)return ;
    
    cout<<details<<node->val<<","<<"Height:"<<node->height<<endl;
    
    display(node->left,"Left child of"+to_string(node->val)+":");
    display(node->right,"Right child of"+to_string(node->val)+":");
    
}

//to call the display function
void display(){
    display(root,"Root Node:");
}


Node* rightRotate(Node* p){
    Node* c=p->left;
    Node* t=c->right;
    
    c->right=p;
    p->left=t;
    
    p->height=max(height(p->left),height(p->right)+1);
    c->height=max(height(c->left),height(c->right)+1);
    
    return c;
}

Node* leftRotate(Node* c){
    Node* p=c->right;
    Node* t=p->left;
    
    p->left=c;
    c->right=t;
    
    p->height=max(height(p->left),height(p->right)+1);
    c->height=max(height(c->left),height(c->right)+1);
    
    return p;
    
}

Node* rotate(Node* node){
    //it means left case
    if(height(node->left)-height(node->right)>1){
        //left->left->case
        if(height(node->left->left)-height(node->left->right)>0){
            return rightRotate(node);
        }
         
        if(height(node->left->left)-height(node->left->right)<0){
           // left->right->case
            node->left=leftRotate(node->left);
            return rightRotate(node);
        }
    }
         
    if(height(node->left)-height(node->right)<-1){
        //right->right->case
        if(height(node->right->left)-height(node->right->right)<0){
            return leftRotate(node);
        }
         
        if(height(node->right->left)-height(node->right->right)>0){
           // left->right->case
            node->right=rightRotate(node->right);
            return leftRotate(node);
        }
        
    }
    return node; 
      
}

//logic to insert
Node* insert(int value,Node* node){
    
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
    
    node->height=max(height(node->left),height(node->right))+1;
    
    return rotate(node);
}

//Function to call insert
void insert(int value){
   root=insert(value,root);
}
//function ti insert many value in tree using the vector value
void populate(vector<int> &nums){
    for(int i=0;i<nums.size();i++){
        insert(nums[i]);
    }
}

//logic to check tree is balanced
bool balanced(Node* node){
    if(node==nullptr)return true;
    
    int lh=height(node->left);
    int rh=height(node->right);
    
    return abs(lh-rh)<=1 && balanced(node->left) && balanced(node->right);
}

//to call balanced function
bool isbalanced(){
    return balanced(root);
}

int main() {

     vector<int> nums={1,2,3,4,5,6,7};//2,3,4,5,6
    
    populate(nums);
   
     display();
    
     if(balanced(root)){
         cout<<"I am balanced";
     }
     else cout<<"I am not balanced";
    
}
