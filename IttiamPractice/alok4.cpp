#include<bits/stdc++.h>
#define N 100005
#define ll long long
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define foreach(v,it) for(__typeof((v).begin())it=(v).begin();it!=(v).end();it++)
using namespace std;
vector<pll> adj[N];
vector<ll> graph[N];
ll nodes[N];
bool visited[N];
init(ll no)
{
    for(ll i=0;i<=no;i++)
    {
        visited[i]=false;
        nodes[i]=0;
    }
}
int dfs(ll src)
{
    visited[src]=true;
    ll cnt=1;
    foreach(adj[src],it)
    {
        ll v=(*it).ss;
        if(!visited[v])
            cnt+=dfs(v);
    }
    return nodes[src]=cnt;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,i;
        cin>>n;
        vector<pll> quer;
        ll maxi=0;ll mini=10000000;
        for(i=1;i<n;i++)
        {
            ll u,v,w;
            cin>>u>>v>>w;
            adj[u].pb(mp(w,v));
            adj[v].pb(mp(w,u));
            if(w==1)
            {
               quer.pb(mp(u,v));
               ll mu=min(u,v);
               ll mv=max(u,v);
               if(mini>mu)
               {
                   mini=mu;
               }
               if(maxi<mv)
               {
                   maxi=mv;
               }

            }

        }
        init(n);
        dfs(1);
        /*foreach(quer,it)
        {
            ll u=(*it).ff; ll v=(*it).ss;
            ll k=min(nodes[u],nodes[v]);

            ll a=k;ll b=n-k;
            ll ans=((n)*(n-1)/2);
            ans=ans-(k*(k-1))/2-((n-k)*(n-k-1))/2;
            cout<<"k : "<<k<<" ans : "<<ans<<" ";
        }
        cout<<endl;*/
        ll k=min(nodes[mini],nodes[maxi]);

            ll a=k;ll b=n-k;
            ll ans=((n)*(n-1)/2);
            ans=ans-(k*(k-1))/2-((n-k)*(n-k-1))/2;
            cout<<"k : "<<k<<" ans : "<<ans<<" ";
    }
    return 0;
}
