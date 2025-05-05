#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int s=100;
vector<int>adjlist[s];
bool visited[s];
void bfsno(int start){
    queue<int>q;
    visited[start]=true;
    q.push(start);
    while(!q.empty()){
        int v=q.front();
        cout<<v<<" ";
        q.pop();
        for(int i=0;i<adjlist[v].size();i++){
            int n=adjlist[v][i];
            if(!visited[n]){
                visited[n]=true;
                q.push(n);
            }
        }
    }
}
int main(){
    int n,e;
    cout<<"enter number of vertices:";
    cin>>n;
    cout<<"enter a number of edges:";
    cin>>e;
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    cout<<"enter a pair of vertex and edge:";
    for(int i=0;i<e;i++){
        int u,p;
        
        cin>>u>>p;
        adjlist[u].push_back(p);
        adjlist[p].push_back(u);

    }
    int start;
    cout<<"enter a statring point:";
    cin>>start;
    cout<<"bfs traversal:";
    bfsno(start);
    return 0;


}