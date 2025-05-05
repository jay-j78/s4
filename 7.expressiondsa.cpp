#include<iostream>
#include<stack>
using namespace std;
struct tNode{
    char data;
    tNode*left;
    tNode*right;
    tNode(int val){
        data=val;
        left=right=nullptr;
    }
};
bool isope(char ch){
    return ch=='+'||ch=='-'||ch=='*'||ch=='/';
}
tNode* addtree(const string& prefix){
    stack<tNode*>s;
    for(int i=prefix.size()-1;i>=0;i--){
        char ch=prefix[i];
        tNode* node=new tNode(ch);
        if(isope(ch)){
            tNode*left=s.top();
            s.pop();
            tNode*right=s.top();
            s.pop();
            node->left=left;
            node->right=right;
            
        }
        s.push(node);
    }
    return s.top();
}
void postt(tNode*root){
    stack<tNode*>s1,s2;
    s1.push(root);
    while(!s1.empty()){
        tNode*node=s1.top();
        s1.pop();
        s2.push(node);
        if(node->left)
        s1.push(node->left);
        if(node->right)
        s1.push(node->right);
    }
    while(!s2.empty()){
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
}
void del(tNode*root){
    if(!root) return;
    del(root->left);
    del(root->right);
    delete root;
}
int main(){
    string prefix;
    cout<<"enter aprefix expression for conversion:";
    cin>>prefix;
    tNode*root=addtree(prefix);
    cout<<"post order traversaaal is:"<<endl;;
    postt(root);
    del(root);
    cout<<endl;
    return 0;
}