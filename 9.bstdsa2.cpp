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
    if(val<root->data){
        root->left=insert(root->left,val);
    }
    else{
        root->right=insert(root->right,val);
    }
    return root;

    
}
bool search(Node*root,int key){
    if(root==nullptr){
        return false;
    }
    if(key==root->data){
        return true;
    }
    else if(key>root->data){
        return search(root->right,key);
    }
    else{
        return search(root->left,key);
    }
}
Node*mirror(Node*root){
    if(root==nullptr){
        return nullptr;
    }
    Node*temp=root->left;
    root->left=mirror(root->right);
    root->right=mirror(temp);
    return root;
}
void inorder(Node*root){
    if(root==nullptr){
        return ;
    }
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);

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
    int key;
    cout<<"enter a key for searching:";
    cin>>key;
    if(search(root,key)){
        cout<<"key is found:";
    }
    else{
        cout<<"key is not found:";
    }
    cout<<endl;
    cout<<"mirror of the tree is:";
    root=mirror(root);
    inorder(root);
    return 0;
}