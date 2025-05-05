#include<iostream>
using namespace std;
const int x=100;
int adjmat[x][x];
bool visited[x];
void dfsre(int v,int n)
{
visited[v]=true;
cout<<v<<" ";
for(int i=0;i<n;i++){
    if(adjmat[v][i] == 1 && !visited[i]){
        dfsre(i,n);
    }
}
}
int main(){
    int n,e;
    cout<<"enter a number of vertices:";
    cin>>n;
    cout<<"enter a number of edges:";
    cin>>e;
    for(int i = 0; i < n; i++) {
        visited[i] = false;
        for(int j = 0; j < n; j++) {
            adjmat[i][j] = 0;
        }
    }

    for(int i=0;i<e;i++){
        int u,p;
        cout<<"enter a vertice and edge pair:";
        cin>>u>>p;
        adjmat[u][p]=1;
        adjmat[p][u]=1;
    }
    int start;

    cout<<"enter a starting point:";
    cin>>start;
    cout<<"dfs traverse:";
    dfsre(start,n);
    return 0;
}