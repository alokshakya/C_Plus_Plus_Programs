#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define pll pair<ll,ll>
#define ff first
#define ss second
#define foreach(v,it) for(__typeof((v).begin())it=(v).begin();it!=(v).end();it++)
using namespace std;
const ll MAX = 1e6 + 5;
const ll MAX_DIST=1e9+7;
ll nodes;
vector <pll> bus[MAX];
vector<pll> train[MAX];
vector<pll> r_bus[MAX];
vector<pll> r_train[MAX];

vector<ll> dijkstra(vector<pll> adj,ll source)
{
    vector<ll> dist(nodes+1);
    bool visited[MAX];
    for(ll i=1;i<=nodes;i++)
    {
        dist[i]=1e9;
        visited[i]=false;
    }
    priority_queue<pll, vector<pll>, greater<pll> > Q;
    dist[source]=0;
    Q.push(mp(0, source));
        while(!Q.empty())
        {
            // Select the edge with minimum weight
            pll t = Q.top();
            Q.pop();
            ll x = t.ss;
            // Checking for cycle
            if(visited[x])
            continue;
            visited[x] = true;
                foreach(adj[x],it)
                {
                    ll y = (*it).ss; ll weight=(*it).ff;
                    if(dist[y]>dist[x]+weight)
                        {
                            dist[y]=dist[x]+weight;
                            Q.push(mp(dist[y],y));
                        }
                }
          }
          return dist;
}
//complexity O((v+e)logV)
int main()
{
    ll i,j;
    cin >> nodes;
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
            if(i==j) continue;
            bus[i].pb(mp(bus[i][j],j));
            r_bus[j].pb(mp(bus[i][j],i));

        }
    }
    for(i=1;i<=nodes;i++)
    {
        for(j=1; j<=nodes; j++)
        {
            cin>>train[i][j];
            if(i==j) continue;
            train[i].pb(mp(train[i][j],j));
            r_train[j].pb(mp(train[i][j],i));

        }
    }
    // Selecting 1 as the source node from where all distances are to be calculated
    //dijkstra(1);
    for(int i=2;i<=nodes;i++)
    //cout<<dist[i]<<" ";
    return 0;
}
