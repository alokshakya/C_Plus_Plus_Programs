#include<bits/stdc++.h>
#define N 100005
#define ll long long
#define pll pair<ll,ll>
#define foreach(v,it) for(__typeof((v).begin())it=(v).begin();it!=(v).end();it++)
using namespace std;
vector<ll> adj[N];
bool visited[N];
pll val[N];
ll nodes[N];
ll n,q,i;
ll dfs(ll src) {
    visited[src]=true;
    ll cnt =1;

    foreach(adj[src],it)
    {

        if(!visited[*it])
            cnt+=dfs(*it);
    }
    return nodes[src]=cnt;
}

int main() {
    cin>>n>>q;
    for(int i=1;i<n;i++)
    {  long long a,b;
        cin>>a>>b;
        val[i]=make_pair(a,b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    for(i=0;i<q;i++)
    {   ll x;
        cin>>x;
        ll a = val[x].first;
        ll b = val[x].second;
        ll ans;
        ll k=min(nodes[a],nodes[b]);
        a=k;
        b=n-k;
        ans = (n*(n-1))/2 - (a*(a-1))/2 - (b*(b-1))/2;
        cout<<ans<<"\n";
    }
return 0;
}
