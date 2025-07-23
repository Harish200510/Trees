#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    int startInterval;
    int endInterval;
    Node* left;
    Node* right;
    Node(int start,int end){
        startInterval=start;
        endInterval=end;
        data=0;
        left=right=nullptr;
    }
};

Node* root=nullptr;

Node * constructTree(vector<int>& arr,int start,int end){
    
    if(start==end){
        //leaf node
        Node* leaf=new Node(start,end);
        leaf->data=arr[start];
        return leaf;
    }
    
    //create new node with index you are at
    Node* node=new Node(start,end);
    
    int mid=(start+end)/2;
    
    //before adding value for the current node first go left and right and fill the values in the node and at last add the left and right val
    node->left=constructTree(arr,start,mid);
    
    node->right=constructTree(arr,mid+1,end);
    
    node->data=node->left->data+node->right->data;
    
    return node; 
}

void Segmentree(vector<int>& arr){
    //in the constructTree function just pass the array and start index(interval) and end index(interval)
    root=constructTree(arr,0,arr.size()-1);
}

void display(Node *node){
    
    if(!node)return;
    
    string str="";
    
    if(node->left!=nullptr){
        str=str+"Interval=["+to_string(node->left->startInterval)+"-"+to_string(node->left->endInterval)+"] and data:"+to_string(node->left->data)+"=>";
    }
    else str=str+"No left child";
    
    //for current node
    str=str+"Interval=["+to_string(node->startInterval)+"-"+to_string(node->endInterval)+"] and data:"+to_string(node->data)+"=>";
    
    if(node->right!=nullptr){
        str=str+"Interval=["+to_string(node->right->startInterval)+"-"+to_string(node->right->endInterval)+"] and data:"+to_string(node->right->data);
    }
    else str=str+"No right child";
    
    cout<<str<<endl<<endl;
    
    display(node->left);
    display(node->right);
}

void display(){
    display(root);
}

int query(Node* node,int qsi,int qei){
    
   if(!node)return 0;
    
    if(node->startInterval>=qsi && node->endInterval<=qei){
        return node->data;
    }
    
    if(node->endInterval<qsi || node->startInterval>qei){
        return 0;
    }
 
    return query(node->left,qsi,qei)+query(node->right,qsi,qei);
    
}

int query(int qsi,int qei){
    return query(root,qsi,qei);
}

//update
int update(Node* node,int index,int val){
    
    if(!node)return 0;
    
    if(index>=node->startInterval && index<=node->endInterval){
        
        if(index==node->startInterval && index==node->endInterval){
            node->data=val;
            return node->data;
        }
        else{
            
            int leftAns=update(node->left,index,val);
            int rightAns=update(node->right,index,val);
            
            node->data=leftAns+rightAns;
            
            return node->data;
        }
    }
    return node->data;
}

void update(int index,int val){
   root->data=update(root,index,val);
}

int main() {
   
   vector<int> arr={3,8,6,7,-2,-8,4,9};

   Segmentree(arr);
   
   //update(2,0);
   
   int ans=query(0,2);
   
   cout<<ans<<endl;;
   
   display();
   
    return 0;
}
