#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define pll pair<ll,ll>
#define ff first
#define ss second
#define foreach(v,it) for(__typeof((v).begin())it=(v).begin();it!=(v).end();it++)
using namespace std;
const int MAX = 1e6 + 5;
const int MAX_DIST=1e9+7;
bool visited[MAX];
ll dist[MAX];
vector <pll> adj[MAX];
void init()
{
    for(ll i=0;i<MAX;i++)
    {
        dist[i]=1e9;
        visited[i]=false;
    }
}
void dijkstra(ll source)
{
    //memset(dist,MAX_DIST,sizeof(dist));//set distance to maximum for each vertex
    init();
    //memset(visited,false,sizeof(visited));//set visited array to false
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
}
//complexity O((v+e)logV)
int main()
{
    ll nodes, edges, x, y;
    ll weight, minimumCost;
    cin >> nodes >> edges;
    for(ll i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        adj[x].pb(mp(weight, y));
        //adj[y].pb(mp(weight, x));
    }
    // Selecting 1 as the source node from where all distances are to be calculated
    dijkstra(1);
    for(int i=2;i<=nodes;i++)
    cout<<dist[i]<<" ";
    return 0;
}
