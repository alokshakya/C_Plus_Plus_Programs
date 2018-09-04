#include<bits/stdc++.h>
#define vi vector<int>
#define foreach(it,v) for( __typeof((v).begin())it = (v).begin() ; it != (v).end() ; it++ )
using namespace std;
int n;
void printLevel(vi adj[], int le)
{
    int start=0;
    vector<bool> visited(n,false);
    vi level(n,0);
    level[start]=1;
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
    int co=0;
    for(int i=0;i<n;i++)
    {
        if(level[i]==le)
            co++;

    }
    cout<<co<<endl;
}
int main()
{
    int x,y,a,b,level;
    cin>>n;
    vi adj[n];
    for(int i=0;i<(n-1);i++)
    {
        cin>>x>>y;
        x--;y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cin>>level;
    printLevel(adj,level);
    return 0;
}
