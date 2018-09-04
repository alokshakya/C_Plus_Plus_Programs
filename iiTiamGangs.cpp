#include<bits/stdc++.h>
#define mp(x,y) make_pair(x,y)
#define f first
#define s second
using namespace std;
void findPath(vector<int> adj[],int source,int dest,int n,vector<int> gangs)
{



}
int main()
{
    int n,m,i,a,b,c;
    cin>>n>>m;
    vector<int> gangs(n);
    vector<int> adj[n];
    for(i=0;i<n;i++)
    {
        cin>>a;
        gangs.push_back(a);
    }
    for(i=0;i<(n-1);i++)
    {
        cin>>b>>c;
        b--;c--;
        adj[b].push_back(c);
        adj[c].push_back(b);
    }
    for(i=0;i<m;i++)
    {
        cin>>b>>c;
        b--;c--;
        findPath(adj,b,c,n,gangs);
    }
    return 0;
}
