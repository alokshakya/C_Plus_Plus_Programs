#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define pll pair<ll,ll>
#define ff first
#define ss second
using namespace std;
const int MAX = 1e4 + 5;
bool visited[MAX];
vector <pll> adj[MAX];

ll prim(ll x)
{
    priority_queue<pll, vector<pll>, greater<pll> > Q;
    int y;
    ll minimumCost = 0;
    pll t;
    Q.push(mp(0, x));
    while(!Q.empty())
    {
        // Select the edge with minimum weight
        t = Q.top();
        Q.pop();
        x = t.ss;
        ll weight=t.ff;
        // Checking for cycle
        if(visited[x])
            continue;
        minimumCost += weight;
        visited[x] = true;
        for(ll i = 0;i < adj[x].size();++i)
        {
            y = adj[x][i].ss;
            if(!visited[y])
                Q.push(adj[x][i]);
        }
    }
    return minimumCost;
}

int main()
{
    ll nodes, edges, x, y;
    ll weight, minimumCost;
    cin >> nodes >> edges;
    for(ll i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        adj[x].pb(mp(weight, y));
        adj[y].pb(mp(weight, x));
    }
    // Selecting 1 as the starting node
    minimumCost = prim(1);
    cout << minimumCost << endl;
    return 0;
}
