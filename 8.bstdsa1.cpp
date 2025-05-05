#include<iostream>
using namespace std;
struct Node{
    int data;
    Node*left;
    Node*right;
    Node(int val){
        data=val;
        left=right=nullptr;
    }
};
Node*insert(Node*root,int val){
    if(root==nullptr)
    return new Node(val);
    if(val>root->data){
        root->right=insert(root->right,val);
    }
    else{
        root->left=insert(root->left,val);
    }
    return root;
}
int height(Node*root){
    if(root==nullptr)
    
    return 0;
    else if(root->left==nullptr && root->right==nullptr)
    return 0;
    
    return (1 + max(height(root->left),height(root->right)));
    
    }
int minimum(Node*root){
    if(root==nullptr){
        return 0;
    }
    while(root->left!=nullptr){
        root=root->left;
    }
    return root->data;
}
int main(){
    Node*root=nullptr;
    int n,val;
    cout<<"enter a number of nodes in bst:";
    cin>>n;
    cout<<"enter a values of nodes:";
    for(int i=0;i<n;i++){
        cin>>val;
    root=insert(root,val);
    }
    cout<<"height of the bst is:"<<height(root);
    
    cout<<endl;
    cout<<"minimum value in the bst is:"<<minimum(root);
    
    return 0;
}