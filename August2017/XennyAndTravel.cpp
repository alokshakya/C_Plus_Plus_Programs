#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX_DIST=1e9+7;
const int MAX=1251;
ll nodes,edges;
ll bus[MAX][MAX];
ll train[MAX][MAX];
int main()
{
    ll i,j,k;
    cin>>nodes;
    ll graph[nodes+1][nodes+1];
    ll times=edges;
    for(i=1;i<=nodes;i++)
    {
        for(j=1; j<=nodes; j++)
        {
            bus[i][j]=MAX_DIST;
            train[i][j]=MAX_DIST;
        }
    }
    for(i=1;i<=nodes;i++)
    {
        for(j=1; j<=nodes; j++)
        {
            cin>>bus[i][j];

        }
    }
    for(i=1;i<=nodes;i++)
    {
        for(j=1; j<=nodes; j++)
        {
            cin>>train[i][j];

        }
    }
    // calculate all pair shortest path for bus
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
                    if (bus[i][k] + bus[k][j] < bus[i][j])
                        bus[i][j] = bus[i][k] + bus[k][j];
                    if (train[i][k] + train[k][j] < train[i][j])
                        train[i][j] = train[i][k] + train[k][j];


                }
            }
        }


ll src,dst;
cin>>src>>dst;
ll mi1=MAX_DIST;
ll mi2=MAX_DIST;
    for(i=1;i<=nodes;i++)
    {
        if(i==src || i==dst) continue;
        if(mi1>bus[src][i]+train[i][dst])
        {
            mi1=bus[src][i]+train[i][dst];
        }
        if(mi2>train[src][i]+bus[i][dst])
            mi2=train[src][i]+bus[i][dst];
    }
    if(mi1<mi2)
        cout<<mi1<<endl;
    else
        cout<<mi2<<endl;



   return 0;
}


