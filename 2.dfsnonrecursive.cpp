#include<iostream>
#include<stack>
using namespace std;
const int y=100;
int adjmat[y][y];
bool visited[y];
void dfsnon(int start,int n){
    stack<int>s;
    s.push(start);
    visited[start]=true;
    while(!s.empty()){
        int v=s.top();
        cout<<v<<" ";
        s.pop();
        for(int i=n-1;i>=0;i--){
            if(adjmat[v][i]==1 && !visited[i]){
                s.push(i);
                visited[i]=true;
            }
        }
    }
}
int main(){
    int n,e;
    cout<<"enter a nnumber of vertices:";
    cin>>n;
    cout<<"enter a number of edges:";
    cin>>e;
    for(int i=0;i<n;i++){
        visited[i]=false;
        for(int j=0;j<n;j++){
            adjmat[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int u,v;
        cout<<"enter a vertex and edge pair:";
        cin>>u>>v;
        adjmat[u][v]=1;
        adjmat[v][u]=1;
    }
    int start;
    cout<<"enter a starting point:";
    cin>>start;
    cout<<"dfs traversal is:";
    dfsnon(start,n);
    return 0;
}