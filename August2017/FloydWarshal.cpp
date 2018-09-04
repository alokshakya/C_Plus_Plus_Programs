#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX_DIST=1e4;
const int MAX=1005;
ll nodes,edges;
vector<ll> parent[MAX][MAX];
ll graph[MAX][MAX];
void floydWarshall()
{
    ll i,j,k;
    for (k = 1; k <= nodes; k++)
    {
        // Pick all vertices as source one by one
        for (i = 1; i <=nodes; i++)
        {
            // Pick all vertices as destination for the
            // above picked source
            for (j = 1; j <=nodes; j++)
            {
                // If vertex k is on the shortest path from
                // i to j, then update the value of dist[i][j]
                if (graph[i][k] + graph[k][j] < graph[i][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                    parent[i][j].push_back(k);
                }


            }
        }
    }
}
int main()
{
    ll i,j,k;
    cin>>nodes>>edges;
    //ll graph[nodes+1][nodes+1];
    ll times=edges;
    for(i=1;i<=nodes;i++)
    {
        for(j=1; j<=nodes; j++)
        {
            graph[i][j]=MAX_DIST;
        }
    }
    while(times--)
    {
        ll a,b,weight;
        cin>>a>>b>>weight;
        graph[a][b]=weight;
    }
    floydWarshall();
    cout<<"\t\t===Solution Matrix==="<<endl;
    //print matrix
    for(i=1;i<=nodes;++i)
    {
        for(j=1;j<=nodes;++j)
        {
            cout<<graph[i][j]<<" \t";
        }
        cout<<"\n";

    }
   return 0;
}
/*
*Input

8 11
1 8 8
8 7 1
7 6 -1
5 6 -1
4 5 3
3 4 1
3 2 1
1 2 10
7 2 -4
2 6 2
6 3 -2

*/

