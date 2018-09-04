#include<bits/stdc++.h>
#define N 1005
using namespace std;
int adjmat[N][N];//for graph
int main()
{
    int n,m,i,j;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        adjmat[x][y]=adjmat[y][x]=1;
    }
    int q;
    cin>>q;
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        if(adjmat[a][b] || adjmat[b][a])
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}
