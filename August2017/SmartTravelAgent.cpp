#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define pll pair<ll,ll>
#define ff first
#define ss second
#define foreach(v,it) for(__typeof((v).begin())it=(v).begin();it!=(v).end();it++)
using namespace std;
const int MAX = 1e2 + 5;
const int MAX_DIST=1e9+5;
bool visited[MAX];
ll dist[MAX];
ll parent[MAX];
vector <pll> adj[MAX];
ll nodes,edges;
void init(ll n)
{
    for(ll i=0;i<=n;i++)
    {
        dist[i]=-1;
        visited[i]=false;
        parent[i]=-1;
    }
}
void maxDijkstra(ll source)
{
    init(nodes);
    priority_queue<pll, vector<pll> > Q;
    dist[source]=MAX_DIST;
    Q.push(mp(MAX_DIST, source));
        while(!Q.empty())
        {
            // Select the edge with minimum weight
            pll t = Q.top();
            Q.pop();
            ll x = t.ss;
            ll di=t.ff;
                foreach(adj[x],it)
                {
                    ll y = (*it).ss; ll weight=(*it).ff;
                    ll minD=min(di,weight);
                    if(minD>dist[y])
                        {
                            dist[y]=minD;
                            parent[y]=x;
                            Q.push(mp(dist[y],y));
                        }
                }
          }
}
void printPath(int s, int d){
	if(s==d)
		cout<<d<<" ";
	else
	{
		printPath(s,parent[d]);
		cout<<d<<" ";
	}
}
//complexity O((v+e)logV)
int main()
{
    ll x,y,weight, minimumCost;
    cin >> nodes >> edges;
    for(ll i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        adj[x].pb(mp(weight, y));
        adj[y].pb(mp(weight, x));
    }
    ll s,d,t;
    cin>>s>>d>>t;
    maxDijkstra(s);
    // Selecting s as the source node from where all distances are to be calculated
    printPath(s,d);
    ll ans = t / (dist[d]-1);
	if(t%(dist[d]-1)!=0){
		ans++;
	}
	cout<<endl;
	cout<<ans<<endl;
    return 0;
}
