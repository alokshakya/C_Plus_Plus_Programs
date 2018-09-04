#include <bits/stdc++.h>
#define ll long long
#define foreach(v,it) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define vl vector<ll>
#define N 100005
using namespace std;
vl adj[N];
ll ar[N];
ll n,k;
ll bitV[N*100];
ll ans=0;
void dfs(int s, ll xo)
{
	xo^=ar[s];
	ans+=bitV[xo^k];
	bitV[xo]++;

	foreach(adj[s],it)
	{
		dfs(*it,xo);
	}
	bitV[xo]--;

}
int main()
{
	cin>>n>>k;
	ll i;
	for(i=1;i<=n;i++)
		cin>>ar[i];
	bitV[0]=1;
	ll x;
	for(i=1;i<n;i++)
	{
		cin>>x;
		adj[x].push_back(i+1);
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}
