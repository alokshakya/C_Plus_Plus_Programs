#include<bits/stdc++.h>
#define N 100005
#define foreach(v,it) for(__typeof((v).begin())it=(v).begin();it!=(v).end();it++)
using namespace std;
vector<int> adj[N];
bool visited[N]={false};
int n,m;
void dfs(int s)
{
    if(visited[s])
        return;
    visited[s]=true;
    foreach(adj[s],it)
    {
        dfs(*it);
    }
   // cout<<"nodes "<<s<<endl;
}
int countEdges(int s)
{
    queue<int> q;
    q.push(s);
    visited[s]=true;
    int edge=0;
    edge+=adj[s].size();
    while(!q.empty())
    {
        int t=q.front();q.pop();
        foreach(adj[t],it)
        {
            if(!visited[*it])
            {
                edge+=adj[*it].size();
                visited[*it]=true;
                q.push(*it);
            }
        }
    }
    return edge/2;
}
int main()
{
    cin>>n>>m;
    int i;
    for(i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> connected;
    for(i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs(i);
            connected.push_back(i);
        }
    }
   // visited[N]={false}; not initializes visited array to false so never use
   memset(visited,false,sizeof(visited)); //this works fine so always use it.
    int maxi=0;
    foreach(connected,it)
    {
        int s=countEdges(*it);
        //cout<<"edges "<<s<<endl;
        if(maxi<s)
            maxi=s;
    }
    cout<<maxi<<endl;
    return 0;
}

