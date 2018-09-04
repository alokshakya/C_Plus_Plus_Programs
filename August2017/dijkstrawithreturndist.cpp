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
ll nodes;
void init()
{
    for(ll i=0;i<=nodes;i++)
    {
        dist[i]=1e9;
        visited[i]=false;
    }
}
void dijkstra(vector<pll> adj[MAX],ll source)
{
    init();
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
    ll weight, i,j;
    cin >> nodes;
    vector <pll> bus[nodes+1];
    vector <pll> r_bus[nodes+1];
    vector <pll> train[nodes+1];
    vector <pll> r_train[nodes+1];
    for(i=1;i<=nodes;i++)
    {
        for(j=1; j<=nodes; j++)
        {
            cin>>weight;
            if(i==j) continue;
            bus[i].pb(mp(weight,j));
            r_bus[j].pb(mp(weight,i));//reverse graph

        }
    }
    for(i=1;i<=nodes;i++)
    {
        for(j=1; j<=nodes; j++)
        {
            cin>>weight;
            if(i==j) continue;
            train[i].pb(mp(weight,j));
            r_train[j].pb(mp(weight,i));
        }
    }
    ll src,dst;
    cin>>src>>dst;
    // Selecting 1 as the source node from where all distances are to be calculated
    dijkstra(bus,src);
    ll busD[nodes+1];
    for(int i=1;i<=nodes;i++)
        busD[i]=dist[i];
    dijkstra(r_bus,dst);
    ll r_busD[nodes+1];
    for(int i=1;i<=nodes;i++)
        r_busD[i]=dist[i];
    dijkstra(train,src);
    ll trainD[nodes+1];
    for(int i=1;i<=nodes;i++)
        trainD[i]=dist[i];
    dijkstra(r_train,dst);
    ll r_trainD[nodes+1];
    for(int i=1;i<=nodes;i++)
        r_trainD[i]=dist[i];
    ll mi1=MAX_DIST;
    ll mi2=MAX_DIST;
    for(i=1;i<=nodes;i++)
    {
        if(i==src || i==dst) continue;
        if(mi1>busD[i]+r_trainD[i])
        {
            mi1=busD[i]+r_trainD[i];
        }
        if(mi2>trainD[i]+r_busD[i])
            mi2=trainD[i]+r_busD[i];

    }
    if(mi1<mi2)
        cout<<mi1<<endl;
    else
        cout<<mi2<<endl;

    return 0;
}
