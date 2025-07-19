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


bool isEmpty(Node* root){
    return root==nullptr;
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
    
    return node;
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

//if the array is sorted then this function will balance the tree
void populateSorted(vector<int> &nums,int start,int end){
    
    if(start>=end)return;
    

    int mid=(start+end)/2;
   
    insert(nums[mid]);
    
    populateSorted(nums,start,mid);
   
    populateSorted(nums,mid+1,end);
    
}

//this will call the populateSorted function
void populateSorted(vector<int> &nums){
    populateSorted(nums,0,nums.size());
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
    
     if (is_sorted(nums.begin(), nums.end())) populate(nums);
     else populateSorted(nums);
    
     display();
    
     if(balanced(root)){
         cout<<"I am balanced";
     }
     else cout<<"I am not balanced";
    
}
