#include<bits/stdc++.h>
#define ll long long
#define pll pair< ll, ll >
#define cll pair<char,pii>
#define vl vector < ll >
#define vll vector<pll>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define foreach(v,it) for( __typeof((v).begin())it = (v).begin() ; it != (v).end() ; it++ )

#define llu unsigned long long
#define MOD 1000000007
#define INF 2000000000
#define dbg(x) { cout<< #x << ": " << (x) << endl; }
#define dbg2(x,y) { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) << endl; }
#define all(x) x.begin(),x.end()
#define mset(x, v) memset(x, v, sizeof(x))
#define N 1005
#define MAX 100000
#define fast_io {ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);}
using namespace std;
ll n,m,k,i;
vector<ll> adj[N];
ll val[N];

int main()
{
    fast_io;
    cin>>n>>m>>k;
    for(i=1;i<=n;i++)
        cin>>val[i];
    for(i=0;i<m;i++)
    {
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for(i=1;i<=n;i++)
    {
        vll a;
        foreach(adj[i],it)
        {
            a.pb(mp(val[*it],*it));

        }
        if(a.size()<k)
            cout<<-1<<endl;
        else
        {
            sort(all(a),greater<pll>());
            ll ans=a[k-1].ss;
            cout<<ans<<endl;
        }
    }

    return 0;
}
