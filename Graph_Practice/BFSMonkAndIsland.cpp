#include<bits/stdc++.h>
#define vi vector<int>
#define foreach(it,v) for( __typeof((v).begin())it = (v).begin() ; it != (v).end() ; it++ )
using namespace std;
int n,m;
void DFS(vi adj[])
{
    int start=0;
    vector<bool> visited(n,false);
    vi level(n,0);
    level[start]=0;
    queue<int> q;
    visited[start]=true;
    q.push(start);
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        foreach(it,adj[t])
        {
            if(!visited[*it])
            {
                level[*it]=level[t]+1;
                q.push(*it);
                visited[*it]=true;
            }
        }

    }

    cout<<level[n-1]<<endl;
}
int main()
{
    int t,x,y,a,b,level;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
    vi adj[n];
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        x--;y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    DFS(adj);

    }

    return 0;
}
