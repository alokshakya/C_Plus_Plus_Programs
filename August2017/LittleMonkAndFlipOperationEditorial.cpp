#include<bits/stdc++.h>
#define N 100005
#define foreach(v,it) for(__typeof((v).begin())it=(v).begin(); it!=(v).end();it++)
using namespace std;
int g[N][33];
vector<int> adj[N];
bool visited[N];
int val[N];
void dfs(int no){
    if(visited[no])return;
    visited[no]=true;
    for(auto x:adj[no]){
        if(visited[x])continue;
        dfs(x);
        for(int i=0;i<32;i++){
            g[no][i]=max(g[no][i],g[x][i]);
        }
    }
    for(int i=0;i<32;i++){
        if(val[no]&(1<<i)){
            if(g[no][i]%2==0)g[no][i]++;
        }
        else{
            if(g[no][i]%2==1)g[no][i]++;
        }
    }
}
int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<n-1;i++){
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
        cin>>val[i];
    dfs(m);
    int ans=0;
    for(int i=0;i<32;i++)
       ans+=g[m][i];
    cout<<ans;
    return 0;
}
